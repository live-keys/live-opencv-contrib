#ifndef FACEMARK_H
#define FACEMARK_H

#include <QObject>
#include <opencv2/face/facemark.hpp>
#include "qmat.h"

namespace lv {

class Facemark: public QObject
{
    Q_OBJECT
public:
    Facemark();
public slots:
    void loadModel(QString filename);
    QVariantList fit(QMat* mat, QVariantList faces);
private:
    cv::Ptr<cv::face::Facemark> m_facemark;
};

} // namespace

#endif // FACEMARK_H
