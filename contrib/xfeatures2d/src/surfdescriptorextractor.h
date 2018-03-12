#ifndef SURFDESCRIPTOREXTRACTOR_H
#define SURFDESCRIPTOREXTRACTOR_H

#include "qdescriptorextractor.h"

namespace lv{

class SURFDescriptorExtractor : public QDescriptorExtractor{

    Q_OBJECT

public:
    explicit SURFDescriptorExtractor(QQuickItem *parent = 0);
    ~SURFDescriptorExtractor();

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

#endif // SURFDESCRIPTOREXTRACTOR_H
