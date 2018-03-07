#include "tracker.h"
#include "qmatnode.h"
#include <QSGSimpleMaterial>

namespace lv{

Tracker::Tracker(QQuickItem *parent)
    : QQuickItem(parent)
    , m_tracker(cv::Ptr<cv::Tracker>())
    , m_in(QMat::nullMat())
    , m_display(new QMat)
    , m_displayColor(cv::Scalar(255, 255, 0))
    , m_displayDirty(false)
{
    setFlag(ItemHasContents, true);
}

Tracker::Tracker(cv::Ptr<cv::Tracker> tracker, QQuickItem *parent)
    : QQuickItem(parent)
    , m_tracker(tracker)
    , m_in(QMat::nullMat())
    , m_display(new QMat)
    , m_displayColor(cv::Scalar(255, 255, 0))
    , m_displayDirty(false)
{
    setFlag(ItemHasContents, true);
}

Tracker::~Tracker(){
    delete m_display;
}

cv::Ptr<cv::Tracker> Tracker::tracker(){
    return m_tracker;
}

void Tracker::initializeTracker(cv::Ptr<cv::Tracker> tracker){
    m_tracker = tracker;
    track();
}

void Tracker::track(){
    if ( m_tracker != nullptr && !m_in->cvMat()->empty() && isComponentComplete() ){
         m_tracker->update(*m_in->cvMat(), m_boundingBoxInternal);
         m_boundingBox.setX(m_boundingBoxInternal.x);
         m_boundingBox.setY(m_boundingBoxInternal.y);
         m_boundingBox.setWidth(m_boundingBoxInternal.width);
         m_boundingBox.setHeight(m_boundingBoxInternal.height);
         emit boundingBoxChanged();
         m_displayDirty = true;
         update();
    }
}

void Tracker::componentComplete(){
    QQuickItem::componentComplete();
    track();
}

QSGNode* Tracker::updatePaintNode(QSGNode *node, UpdatePaintNodeData *){
    if ( m_displayDirty && !m_in->cvMat()->empty() ){
        m_in->cvMat()->copyTo(*m_display->cvMat());
        cv::rectangle(*m_display->cvMat(), m_boundingBoxInternal, cv::Scalar());
    }

    QMatNode* n = static_cast<QMatNode*>(node);
    if (!node)
        n = new QMatNode();

    QMatState* state = static_cast<QSGSimpleMaterial<QMatState>*>(n->material())->state();
    state->mat          = m_display;
    state->textureSync  = false;
    state->linearFilter = false;
    n->markDirty(QSGNode::DirtyGeometry | QSGNode::DirtyMaterial);

    return n;
}

} // namespace
