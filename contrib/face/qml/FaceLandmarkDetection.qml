import QtQuick 2.0
import lcvcore 1.0
import base 1.0
import lcvimgproc 1.0
import opencv.contrib.face 1.0

Act {
    id: faceLandmarkDetection
    property var facemark: Facemark {}
    property string file: "face_landmark_model.dat"

    property Mat mat: null
    property var faces: null

    run: function (mat, faces){
        if (file == "" || !mat || !faces) return null
        // facemark.loadModel(file)
        var result = facemark.fit(mat, faces)
        return result
    }
    args: ['$mat', '$faces']
}
