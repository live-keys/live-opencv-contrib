#ifndef TRACKERMIL_H
#define TRACKERMIL_H

#include "tracker.h"

namespace lv{

class TrackerMIL : public Tracker{

    Q_OBJECT

public:
    explicit TrackerMIL(QQuickItem* parent = 0);
    ~TrackerMIL(){}

    void initialize(const QVariantMap &params);
};

}// namespace

#endif // TRACKERMIL_H
