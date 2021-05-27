#include "surfdescriptorextractor.h"
#include "opencv2/xfeatures2d.hpp"
#include "qlicensesettings.h"
#include "live/settings.h"
#include <QQmlEngine>
#include <QQmlContext>

namespace lv{

SURFDescriptorExtractor::SURFDescriptorExtractor(QQuickItem *parent)
    : QDescriptorExtractor(cv::xfeatures2d::SURF::create(), parent)
{
}

SURFDescriptorExtractor::~SURFDescriptorExtractor(){
}

void SURFDescriptorExtractor::initialize(const QVariantMap &){
    initializeExtractor(cv::xfeatures2d::SURF::create());
}

void SURFDescriptorExtractor::licenseAccepted(const QString &id){
    if ( id == "surf" ){
        m_licenseAccepted = true;
        compute();
    }
}

void SURFDescriptorExtractor::compute(){
    if ( m_licenseAccepted ){
        QDescriptorExtractor::compute();
    }
}

void SURFDescriptorExtractor::componentComplete(){
    QQmlEngine* engine = qmlEngine(this);
    if ( engine ){
        QObject* livekeys = engine->rootContext()->contextProperty("livekeys").value<QObject*>();
        lv::Settings* settings = static_cast<lv::Settings*>(livekeys->property("settings").value<QObject*>());

        QLicenseSettings* ls = qobject_cast<QLicenseSettings*>(settings->file("license"));
        m_licenseAccepted = ls->require(
            "surf",
            "SURF License",
            "The SURF component is valid for research/academic use only. Accepting this license means you comply "
            "and understand the rules on how to use it."
            "Please check the websitefor more information http://www.vision.ee.ethz.ch/~surf/download.html"
        );
        if ( !m_licenseAccepted ){
            QObject::connect(ls, SIGNAL(licenseAccepted(QString)), this, SLOT(licenseAccepted(QString)));
        }
    }

    QDescriptorExtractor::componentComplete();
}

} // namespace
