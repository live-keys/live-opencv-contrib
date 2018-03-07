#include "tracking_plugin.h"
#include "tracker.h"
#include "trackermil.h"
#include "trackerboosting.h"
#include "trackergoturn.h"
#include "trackerkcf.h"
#include "trackermedianflow.h"
#include "trackertld.h"
#include <qqml.h>

void TrackingPlugin::registerTypes(const char *uri){
    qmlRegisterType<lv::Tracker>(          uri, 1, 0, "Tracker");
    qmlRegisterType<lv::TrackerMIL>(       uri, 1, 0, "TrackerMIL");
    qmlRegisterType<lv::TrackerBoosting>(  uri, 1, 0, "TrackerBoosting");
    qmlRegisterType<lv::TrackerGOTURN>(    uri, 1, 0, "TrackerGOTURN");
    qmlRegisterType<lv::TrackerKCF>(       uri, 1, 0, "TrackerKCF");
    qmlRegisterType<lv::TrackerMedianFlow>(uri, 1, 0, "TrackerMedianFlow");
    qmlRegisterType<lv::TrackerTLD>(       uri, 1, 0, "TrackerTLD");
}
