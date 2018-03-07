#include "trackerboosting.h"

namespace lv{

TrackerBoosting::TrackerBoosting(QQuickItem *parent)
    : Tracker(cv::TrackerBoosting::create(), parent)
{
}

void TrackerBoosting::initialize(const QVariantMap &params){
    cv::TrackerBoosting::Params p;

    if ( params.contains("numClassifiers") )
        p.numClassifiers = params["numClassifiers"].toInt();
    if ( params.contains("samplerOverlap") )
        p.samplerOverlap = params["samplerOverlap"].toFloat();
    if ( params.contains("samplerSearchFactor") )
        p.samplerSearchFactor = params["samplerSearchFactor"].toFloat();
    if ( params.contains("iterationInit") )
        p.iterationInit = params["iterationInit"].toInt();
    if ( params.contains("featureSetNumFeatures") )
        p.featureSetNumFeatures = params["featureSetNumFeatures"].toInt();

    initializeTracker(cv::TrackerBoosting::create(p));
}

}// namespace
