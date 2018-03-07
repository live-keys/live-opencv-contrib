#include "trackertld.h"

namespace lv{

TrackerTLD::TrackerTLD(QQuickItem *parent)
    : Tracker(cv::TrackerTLD::create(), parent)
{
}

void TrackerTLD::initialize(const QVariantMap &){
    cv::TrackerTLD::Params p;
    initializeTracker(cv::TrackerTLD::create(p));
}


}// namespace
