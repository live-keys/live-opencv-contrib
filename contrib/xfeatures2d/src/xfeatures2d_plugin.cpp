#include "xfeatures2d_plugin.h"

#include "freakdescriptorextractor.h"
#include "briefdescriptorextractor.h"
#include "starfeaturedetector.h"

#ifdef USING_SIFT
#include "siftfeaturedetector.h"
#include "siftdescriptorextractor.h"
#endif

#ifdef USING_SURF
#include "surffeaturedetector.h"
#include "surfdescriptorextractor.h"
#endif


#include <qqml.h>

void XFeatures2dPlugin::registerTypes(const char *uri){
#ifdef USING_SIFT
    qmlRegisterType<lv::SIFTFeatureDetector>(    uri, 1, 0, "SIFTFeatureDetector");
    qmlRegisterType<lv::SIFTDescriptorExtractor>(uri, 1, 0, "SIFTDescriptorExtractor");
#endif

#ifdef USING_SURF
    qmlRegisterType<lv::SURFFeatureDetector>(    uri, 1, 0, "SURFFeatureDetector");
    qmlRegisterType<lv::SURFDescriptorExtractor>(uri, 1, 0, "SURFDescriptorExtractor");
#endif

    qmlRegisterType<lv::FreakDescriptorExtractor>(uri, 1, 0, "FreakDescriptorExtractor");
    qmlRegisterType<lv::BriefDescriptorExtractor>(uri, 1, 0, "BriefDescriptorExtractor");
    qmlRegisterType<lv::StarFeatureDetector>(     uri, 1, 0, "StarFeatureDetector");
}
