PLUGIN_NAME = tracking
PLUGIN_PATH = opencv/contrib/tracking

## PLUGIN_NAME and PLUGIN_PATH must be set up prior to including this config file
include($$LIVEKEYS_DEV_PATH/project/plugin.pri)
TARGET = live_opencv_tracking

uri = opencv.contrib.tracking

DEFINES += Q_LCV

## Dependencies

linkPlugin(live,    live)
linkPlugin(lcvcore, lcvcore)

## Deploying qml is handled by the plugin.pri configuration

## Source

include($$PWD/src/tracking.pri)
include($$LIVEKEYS_DEV_PATH/project/3rdparty/opencv.pri)

OTHER_FILES *= \
    qml/*.qml \
    qml/qmldir
