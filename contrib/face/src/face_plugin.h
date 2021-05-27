#ifndef FACEPLUGIN_H
#define FACEPLUGIN_H

#include <QQmlExtensionPlugin>

class FacePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // FACEPLUGIN_H
