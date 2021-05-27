#include "face_plugin.h"
#include "facemark.h"

#include <qqml.h>

void FacePlugin::registerTypes(const char *uri)
{
    qmlRegisterType<lv::Facemark>(uri, 1, 0, "Facemark");
}
