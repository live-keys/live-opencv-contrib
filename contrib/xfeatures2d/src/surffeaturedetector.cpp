#include "surffeaturedetector.h"
#include "opencv2/xfeatures2d.hpp"
#include "qlicensesettings.h"
#include "live/settings.h"
#include <QQmlEngine>
#include <QQmlContext>

namespace lv{

SURFFeatureDetector::SURFFeatureDetector(QQuickItem *parent)
    : QFeatureDetector(cv::xfeatures2d::SURF::create(), parent)
    , m_licenseAccepted(false)
{

}

SURFFeatureDetector::~SURFFeatureDetector(){
}

void SURFFeatureDetector::initialize(const QVariantMap &settings){
    double hessianThreshold = 100;
    int nOctaves = 4;
    int nOctaveLayers = 3;
    bool extended = false;
    bool upright = false;

    if ( settings.contains("hessianThreshold") )
        hessianThreshold = settings["hessianThreshold"].toDouble();
    if ( settings.contains("nOctaves") )
        nOctaves = settings["nOctaves"].toInt();
    if ( settings.contains("nOctaveLayers") )
        nOctaveLayers = settings["nOctaveLayers"].toInt();
    if ( settings.contains("extended") )
        extended = settings["extended"].toBool();
    if ( settings.contains("upright") )
        upright = settings["upright"].toBool();


    initializeDetector(cv::xfeatures2d::SURF::create(
        hessianThreshold, nOctaves, nOctaveLayers, extended, upright
    ));
}

void SURFFeatureDetector::licenseAccepted(const QString &id){
    if ( id == "surf" ){
        m_licenseAccepted = true;
        detect();
    }
}

void SURFFeatureDetector::detect(){
    if ( m_licenseAccepted ){
        QFeatureDetector::detect();
    }
}

void SURFFeatureDetector::componentComplete(){
    QQmlEngine* engine = qmlEngine(this);
    if ( engine ){
        QObject* livecv = engine->rootContext()->contextProperty("livecv").value<QObject*>();
        lv::Settings* settings = static_cast<lv::Settings*>(livecv->property("settings").value<QObject*>());

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

    QFeatureDetector::componentComplete();
}

}// namespace
