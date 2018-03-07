#ifndef TRACKERBOOSTING_H
#define TRACKERBOOSTING_H

#include "tracker.h"

namespace lv{

class TrackerBoosting : public Tracker{

    Q_OBJECT

public:
    explicit TrackerBoosting(QQuickItem* parent = 0);
    ~TrackerBoosting(){}

    void initialize(const QVariantMap &params);
};

}// namespace

#endif // TRACKERBOOSTING_H
