#ifndef TRACKERGOTURN_H
#define TRACKERGOTURN_H

#include "tracker.h"

namespace lv{

class TrackerGOTURN : public Tracker{

    Q_OBJECT

public:
    explicit TrackerGOTURN(QQuickItem* parent = 0);
    ~TrackerGOTURN(){}

    void initialize(const QVariantMap &params);
};

}// namespace

#endif // TRACKERGOTURN_H
