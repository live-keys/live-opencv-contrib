PLUGIN_NAME = xfeatures2d
PLUGIN_PATH = opencv/contrib/xfeatures2d

## PLUGIN_NAME and PLUGIN_PATH must be set up prior to including this config file
include($$LIVECV_DEV_PATH/project/plugin.pri)
TARGET = live_opencv_xfeatures2d

uri = opencv.contrib.xfeatures2d

DEFINES += Q_LCV

## Dependencies

linkPlugin(live,          live)
linkPlugin(lcvcore,       lcvcore)
linkPlugin(lcvfeatures2d, lcvfeatures2d)
linkLibrary(lvbase, lvbase)

## Deploying qml is handled by the plugin.pri configuration

## Source

include($$PWD/src/xfeatures2d.pri)
include($$LIVECV_DEV_PATH/project/3rdparty/opencv.pri)

OTHER_FILES *= \
    qml/*.qml \
    qml/qmldir
