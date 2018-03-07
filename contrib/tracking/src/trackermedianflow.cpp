#include "trackermedianflow.h"

namespace lv{

TrackerMedianFlow::TrackerMedianFlow(QQuickItem *parent)
    : Tracker(cv::TrackerMedianFlow::create(), parent)
{
}

void TrackerMedianFlow::initialize(const QVariantMap &params){
    cv::TrackerMedianFlow::Params p;

    if ( params.contains("pointsInGrid") )
        p.pointsInGrid = params["pointsInGrid"].toInt();
    if ( params.contains("winSize") ){
        QSize wsize = params["winSize"].toSize();
        p.winSize = cv::Size(wsize.width(), wsize.height());
    }
    if ( params.contains("maxLevel") )
        p.maxLevel = params["maxLevel"].toInt();
    if ( params.contains("termCriteria") ){
        QVariantMap tc = params["termCriteria"].toMap();
        if ( tc.contains("type") )
            p.termCriteria.type = tc["type"].toInt();
        if ( tc.contains("maxCount") )
            p.termCriteria.maxCount = tc["maxCount"].toInt();
        if ( tc.contains("epsilon") )
            p.termCriteria.epsilon = tc["epsilon"].toDouble();
    }
    if ( params.contains("winSizeNCC") ){
        QSize wsize = params["winSizeNCC"].toSize();
        p.winSizeNCC = cv::Size(wsize.width(), wsize.height());
    }

    if ( params.contains("maxMedianLengthOfDisplacementDifference") )
        p.maxMedianLengthOfDisplacementDifference = params["maxMedianLengthOfDisplacementDifference"].toDouble();

    initializeTracker(cv::TrackerMedianFlow::create(p));
}

}// namespace
