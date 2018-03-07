#ifndef TRACKER_H
#define TRACKER_H

#include "qmatdisplay.h"
#include "opencv2/tracking.hpp"

namespace lv{

class Tracker : public QQuickItem{

    Q_OBJECT
    Q_PROPERTY(QMat* input        READ inputMat    WRITE setInputMat    NOTIFY inputChanged)
    Q_PROPERTY(QRect boundingBox  READ boundingBox NOTIFY boundingBoxChanged)
    Q_PROPERTY(QVariantMap params READ params      NOTIFY paramsChanged)

public:
    explicit Tracker(QQuickItem* parent = 0);
    Tracker(cv::Ptr<cv::Tracker> tracker, QQuickItem* parent = 0);
    virtual ~Tracker();

public:
    QMat* inputMat();
    void setInputMat(QMat* mat);

    const QVariantMap& params() const;
    const QRect& boundingBox() const;

public:
    virtual QSGNode* updatePaintNode(QSGNode *, UpdatePaintNodeData *);

public slots:
    void init(QMat* m, const QRect& bbox, const QVariantMap& params = QVariantMap());

signals:
    void inputChanged();
    void boundingBoxChanged();
    void paramsChanged();

protected:
    virtual void initialize(const QVariantMap& params);

    cv::Ptr<cv::Tracker> tracker();
    void initializeTracker(cv::Ptr<cv::Tracker> tracker);
    void track();
    virtual void componentComplete();

private:

    cv::Ptr<cv::Tracker> m_tracker;
    bool                 m_isTrackerInit;
    QMat*                m_in;
    QRect                m_boundingBox;
    cv::Rect2d           m_boundingBoxInternal;
    QVariantMap          m_params;

    QMat*                m_display;
    cv::Scalar           m_displayColor;
    bool                 m_displayDirty;
};

inline QMat* Tracker::inputMat(){
    return m_in;
}

inline void Tracker::setInputMat(QMat *mat){
    if ( mat->cvMat()->empty() )
        return;

    cv::Mat* matData = mat->cvMat();
    if ( implicitWidth() != matData->cols || implicitHeight() != matData->rows ){
        setImplicitWidth(matData->cols);
        setImplicitHeight(matData->rows);
    }

    m_in = mat;
    emit inputChanged();
    track();
}

inline void Tracker::initialize(const QVariantMap &){}

inline const QVariantMap& Tracker::params() const{
    return m_params;
}

inline const QRect& Tracker::boundingBox() const{
    return m_boundingBox;
}

inline void Tracker::init(QMat *m, const QRect &bbox, const QVariantMap &params){
    m_boundingBox = bbox;
    m_params = params;

    initialize(params);
    emit boundingBoxChanged();
    emit paramsChanged();

    if ( !m->cvMat()->empty() && !bbox.isEmpty() ){
        m_tracker->init(*m->cvMat(), cv::Rect(bbox.x(), bbox.y(), bbox.width(), bbox.height()));
    }
}

}// namespace

#endif // TRACKER_H
