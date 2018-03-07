#ifndef TRACKERMEDIANFLOW_H
#define TRACKERMEDIANFLOW_H

#include "tracker.h"

namespace lv{

class TrackerMedianFlow : public Tracker{

    Q_OBJECT

public:
    explicit TrackerMedianFlow(QQuickItem* parent = 0);
    ~TrackerMedianFlow(){}

    void initialize(const QVariantMap &params);
};

}// namespace

#endif // TRACKERMEDIANFLOW_H
