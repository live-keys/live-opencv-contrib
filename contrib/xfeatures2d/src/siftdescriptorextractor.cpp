#include "siftdescriptorextractor.h"
#include "opencv2/xfeatures2d.hpp"
#include "qlicensesettings.h"
#include "live/settings.h"
#include <QQmlEngine>
#include <QQmlContext>

namespace lv{

SIFTDescriptorExtractor::SIFTDescriptorExtractor(QQuickItem *parent)
    : QDescriptorExtractor(cv::xfeatures2d::SIFT::create(), parent)
{
}

SIFTDescriptorExtractor::~SIFTDescriptorExtractor(){
}

void SIFTDescriptorExtractor::initialize(const QVariantMap &){
    initializeExtractor(cv::xfeatures2d::SIFT::create());
}

void SIFTDescriptorExtractor::licenseAccepted(const QString &id){
    if ( id == "sift" ){
        m_licenseAccepted = true;
        compute();
    }
}

void SIFTDescriptorExtractor::compute(){
    if ( m_licenseAccepted ){
        QDescriptorExtractor::compute();
    }
}

void SIFTDescriptorExtractor::componentComplete(){
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

    QDescriptorExtractor::componentComplete();
}

} // namespace
