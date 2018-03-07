import QtQuick 2.3
import lcvcore 1.0
import opencv.contrib.tracking 1.0

Grid{
    spacing: 2
    
    // This sample shows the MIL tracker
    // Click on any vehicle in the image to see it in action
    
    VideoCapture{
        id: videoCapture
        loop: true 
        Component.onCompleted: staticOpen(project.dir() + '/../_videos/amherst-11_2754_3754.avi')
        MouseArea{
            anchors.fill: parent
            onClicked: trackerMIL.init(videoCapture.output, Qt.rect(mouse.x - 20, mouse.y - 20, 40, 40))
        }
        Rectangle{
            width: 40
            height: 40
            color: "#3300ff00"
            x: trackerMIL.boundingBox.x
            y: trackerMIL.boundingBox.y
        }
    }
    
    TrackerMIL{
        id: trackerMIL
        input: videoCapture.output
    }
    
}
