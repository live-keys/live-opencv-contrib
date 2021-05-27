#include "facemark.h"

namespace lv {

Facemark::Facemark()
    : m_facemark(cv::face::createFacemarkKazemi())
{
    loadModel("face_landmark_model.dat");
}

void Facemark::loadModel(QString filename)
{
    m_facemark->loadModel(filename.toStdString());
}

QVariantList Facemark::fit(QMat* mat, QVariantList faces)
{
    auto cv_mat = mat->internal();
    std::vector<cv::Rect> rects;

    for (int i = 0; i < faces.size(); ++i){
        auto face = faces[i].toRect();
        auto rect = cv::Rect(face.x(), face.y(), face.width(), face.height());

        rects.push_back(rect);
    }
    std::vector<std::vector<cv::Point2f>> points;
    m_facemark->fit(cv_mat, rects, points);
    QVariantList result;

    for (unsigned idx = 0; idx < points.size(); ++idx){
        QVariantList part;
        for (unsigned inn = 0; inn < points[idx].size(); ++inn)
            part.push_back(QPointF(points[idx][inn].x, points[idx][inn].y));
        result.push_back(part);
    }

    return result;
}

} // namespace
