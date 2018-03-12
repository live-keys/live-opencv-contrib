#ifndef SIFTDESCRIPTOREXTRACTOR_H
#define SIFTDESCRIPTOREXTRACTOR_H

#include "qdescriptorextractor.h"

namespace lv{

class SIFTDescriptorExtractor : public QDescriptorExtractor{

    Q_OBJECT

public:
    explicit SIFTDescriptorExtractor(QQuickItem *parent = 0);
    ~SIFTDescriptorExtractor();

public slots:
    void licenseAccepted(const QString& id);
    virtual void compute() Q_DECL_OVERRIDE;

protected:
    virtual void componentComplete() Q_DECL_OVERRIDE;
    void initialize(const QVariantMap& params) Q_DECL_OVERRIDE;

private:
    bool m_licenseAccepted;
};

}// namespace

#endif // SIFTDESCRIPTOREXTRACTOR_H
