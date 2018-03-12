import QtQuick 2.3
import QtQuick.Controls 1.3
import live 1.0
import lcvcore 1.0
import lcvfeatures2d 1.0
import opencv.contrib.xfeatures2d 1.0

Column{
    
    spacing: 10
    
    Row{
        
        ImageFile{
            id: imageFile
            source: project.path('../_images/clock.jpg')
        }
        
        StarFeatureDetector{
            id:sIFTFeatureDetector
            input: imageFile.output
        }
        
        BriefDescriptorExtractor{
            id : descriptorExtractor
            keypoints : sIFTFeatureDetector.keypoints
            onDescriptorsChanged : {
                var dim   = descriptors.dimensions()
                var buffer = cv.matToArray(descriptors)
                
                var text = ''
                for ( var i = 0; i < buffer.length; ++i ){
                    text += buffer[i] + ' '
                }
                
                descriptorValues.text = 'Descriptors: ' + dim.width + 'x' + dim.height + '\n' + text
            }
        }
    }
    
    
    Rectangle{
        width : 520
        height : 120
        color : '#091018'

        ScrollView {
            anchors.fill : parent
            style : LiveCVScrollStyle{}

            Text {
                id : descriptorValues
                text : ""
                color : "#eee"
                font.family : "Source Code Pro, Courier New, Courier"
                lineHeight : 1.4
            }
        }
    }
}
