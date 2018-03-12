INCLUDEPATH += $$PWD

HEADERS +=\
    $$PWD/xfeatures2d_plugin.h \
    $$PWD/freakdescriptorextractor.h \
    $$PWD/starfeaturedetector.h \
    $$PWD/briefdescriptorextractor.h

SOURCES += \
    $$PWD/xfeatures2d_plugin.cpp \
    $$PWD/freakdescriptorextractor.cpp \
    $$PWD/starfeaturedetector.cpp \
    $$PWD/briefdescriptorextractor.cpp


equals(BUILD_NON_FREE, true){

    DEFINES += USING_SIFT
    DEFINES += USING_SURF

    HEADERS +=\
        $$PWD/siftfeaturedetector.h \
        $$PWD/siftdescriptorextractor.h \
        $$PWD/surffeaturedetector.h \
        $$PWD/surfdescriptorextractor.h


    SOURCES += \
        $$PWD/siftfeaturedetector.cpp \
        $$PWD/siftdescriptorextractor.cpp \
        $$PWD/surffeaturedetector.cpp \
        $$PWD/surfdescriptorextractor.cpp

}
