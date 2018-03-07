#ifndef TRACKERKCF_H
#define TRACKERKCF_H

#include "tracker.h"

namespace lv{

class TrackerKCF : public Tracker{

    Q_OBJECT

public:
    explicit TrackerKCF(QQuickItem* parent = 0);
    ~TrackerKCF(){}

    void initialize(const QVariantMap &params);
};

}// namespace

#endif // TRACKERKCF_H
