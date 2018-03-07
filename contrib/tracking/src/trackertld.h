#ifndef TRACKERTLD_H
#define TRACKERTLD_H
#include "tracker.h"

namespace lv{

class TrackerTLD : public Tracker{

    Q_OBJECT

public:
    explicit TrackerTLD(QQuickItem* parent = 0);
    ~TrackerTLD(){}

    void initialize(const QVariantMap &params);
};

}// namespace

#endif // TRACKERTLD_H
