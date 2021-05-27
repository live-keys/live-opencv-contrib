PLUGIN_NAME = face
PLUGIN_PATH = opencv/contrib/face

## PLUGIN_NAME and PLUGIN_PATH must be set up prior to including this config file
include($$LIVEKEYS_DEV_PATH/project/plugin.pri)
TARGET = live_opencv_face

uri = opencv.contrib.face

DEFINES += Q_LCV

## Dependencies

linkPlugin(live,          live)
linkPlugin(lcvcore,       lcvcore)
linkLibrary(lvbase, lvbase)
linkLibrary(lvview, lvview)

## Deploying qml is handled by the plugin.pri configuration

## Source

include($$PWD/src/face.pri)
include($$LIVEKEYS_DEV_PATH/project/3rdparty/opencv.pri)

OTHER_FILES *= \
    qml/*.qml \
    qml/qmldir

DISTFILES += \
    qml/FaceLandmarkDetection.qml
