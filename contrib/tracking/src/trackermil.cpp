#include "trackermil.h"

namespace lv{

TrackerMIL::TrackerMIL(QQuickItem *parent)
    : Tracker(cv::TrackerMIL::create(), parent)
{
}

void TrackerMIL::initialize(const QVariantMap &params){
    cv::TrackerMIL::Params p;

    if ( params.contains("samplerInitInRadius") )
        p.samplerInitInRadius = params["samplerInitInRadius"].toFloat();
    if ( params.contains("samplerInitMaxNegNum") )
        p.samplerInitMaxNegNum = params["samplerInitMaxNegNum"].toInt();
    if ( params.contains("samplerSearchWinSize") )
        p.samplerSearchWinSize = params["samplerSearchWinSize"].toFloat();
    if ( params.contains("samplerTrackInRadius") )
        p.samplerTrackInRadius = params["samplerTrackInRadius"].toFloat();
    if ( params.contains("samplerTrackMaxPosNum") )
        p.samplerTrackMaxPosNum = params["samplerTrackMaxPosNum"].toInt();
    if ( params.contains("samplerTrackMaxNegNum") )
        p.samplerTrackMaxNegNum = params["samplerTrackMaxNegNum"].toInt();
    if ( params.contains("featureSetNumFeatures") )
        p.samplerTrackMaxNegNum = params["featureSetNumFeatures"].toInt();

    initializeTracker(cv::TrackerMIL::create(p));
}

}// namespace
