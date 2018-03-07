#include "trackergoturn.h"

namespace lv{

TrackerGOTURN::TrackerGOTURN(QQuickItem *parent)
    : Tracker(cv::TrackerGOTURN::create(), parent)
{
}

void TrackerGOTURN::initialize(const QVariantMap &){
    cv::TrackerGOTURN::Params p;
    initializeTracker(cv::TrackerGOTURN::create(p));
}

}// namespace
