#ifndef SURFFEATUREDETECTOR_H
#define SURFFEATUREDETECTOR_H

#include <QQuickItem>
#include "qfeaturedetector.h"

namespace lv{

class SURFFeatureDetector : public QFeatureDetector{

    Q_OBJECT

public:
    SURFFeatureDetector(QQuickItem* parent = 0);
    ~SURFFeatureDetector();

    void initialize(const QVariantMap& settings) Q_DECL_OVERRIDE;

public slots:
    void licenseAccepted(const QString& id);

protected:
    virtual void detect() Q_DECL_OVERRIDE;
    virtual void componentComplete() Q_DECL_OVERRIDE;

private:
    bool m_licenseAccepted;
};

}// namespace

#endif // SURFFEATUREDETECTOR_H
