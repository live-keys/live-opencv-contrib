#include "siftfeaturedetector.h"
#include "opencv2/xfeatures2d.hpp"
#include "qlicensesettings.h"
#include "live/settings.h"
#include <QQmlEngine>
#include <QQmlContext>

namespace lv{

SIFTFeatureDetector::SIFTFeatureDetector(QQuickItem *parent)
    : QFeatureDetector(cv::xfeatures2d::SIFT::create(), parent)
    , m_licenseAccepted(false)
{

}

SIFTFeatureDetector::~SIFTFeatureDetector(){
}

void SIFTFeatureDetector::initialize(const QVariantMap &settings){
    int nfeatures = 0;
    int nOctaveLayers = 3;
    double contrastThreshold = 0.04;
    double edgeThreshold = 10;
    double sigma = 1.6;

    if ( settings.contains("nfeatures") )
        nfeatures = settings["nfeatures"].toInt();
    if ( settings.contains("nOctaveLayers") )
        nOctaveLayers = settings["nOctaveLayers"].toInt();
    if ( settings.contains("contrastThreshold") )
        contrastThreshold = settings["contrastThreshold"].toDouble();
    if ( settings.contains("edgeThreshold") )
        edgeThreshold = settings["edgeThreshold"].toDouble();
    if ( settings.contains("sigma") )
        sigma = settings["sigma"].toDouble();


    initializeDetector(cv::xfeatures2d::SIFT::create(
        nfeatures, nOctaveLayers, contrastThreshold, edgeThreshold, sigma
    ));
}

void SIFTFeatureDetector::licenseAccepted(const QString &id){
    if ( id == "sift" ){
        m_licenseAccepted = true;
        detect();
    }
}

void SIFTFeatureDetector::detect(){
    if ( m_licenseAccepted ){
        QFeatureDetector::detect();
    }
}

void SIFTFeatureDetector::componentComplete(){
    QQmlEngine* engine = qmlEngine(this);
    if ( engine ){
        QObject* livekeys = engine->rootContext()->contextProperty("livekeys").value<QObject*>();
        lv::Settings* settings = static_cast<lv::Settings*>(livekeys->property("settings").value<QObject*>());

        QLicenseSettings* ls = qobject_cast<QLicenseSettings*>(settings->file("license"));
        m_licenseAccepted = ls->require(
            "sift",
            "SIFT License",
            "The SIFT component is valid for research/academic use only. Accepting this license means you comply "
            "and understand the rules on how to use it."
            "Please check the patent page for more information https://patents.google.com/patent/US6711293"
        );
        if ( !m_licenseAccepted ){
            QObject::connect(ls, SIGNAL(licenseAccepted(QString)), this, SLOT(licenseAccepted(QString)));
        }
    }

    QFeatureDetector::componentComplete();
}

}// namespace
