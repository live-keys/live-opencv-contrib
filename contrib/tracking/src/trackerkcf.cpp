#include "trackerkcf.h"

namespace lv{

TrackerKCF::TrackerKCF(QQuickItem *parent)
    : Tracker(cv::TrackerKCF::create(), parent)
{
}

void TrackerKCF::initialize(const QVariantMap &params){
    cv::TrackerKCF::Params p;

    if ( params.contains("detect_thresh") )
        p.detect_thresh = params["detect_thresh"].toFloat();
    if ( params.contains("sigma") )
        p.sigma = params["sigma"].toFloat();
    if ( params.contains("lambda") )
        p.lambda = params["lambda"].toFloat();
    if ( params.contains("interp_factor") )
        p.interp_factor = params["interp_factor"].toFloat();
    if ( params.contains("output_sigma_factor") )
        p.output_sigma_factor = params["output_sigma_factor"].toFloat();
    if ( params.contains("pca_learning_rate") )
        p.pca_learning_rate = params["pca_learning_rate"].toFloat();

    if ( params.contains("resize") )
        p.resize = params["resize"].toBool();
    if ( params.contains("split_coeff") )
        p.split_coeff = params["split_coeff"].toBool();
    if ( params.contains("wrap_kernel") )
        p.wrap_kernel = params["wrap_kernel"].toBool();
    if ( params.contains("compress_feature") )
        p.compress_feature = params["compress_feature"].toBool();

    if ( params.contains("max_patch_size") )
        p.max_patch_size = params["max_patch_size"].toInt();
    if ( params.contains("compressed_size") )
        p.compressed_size = params["compressed_size"].toInt();
    if ( params.contains("desc_pca") )
        p.desc_pca = params["desc_pca"].toInt();
    if ( params.contains("desc_npca") )
        p.desc_npca = params["desc_npca"].toInt();

    initializeTracker(cv::TrackerKCF::create(p));
}

}// namespace
