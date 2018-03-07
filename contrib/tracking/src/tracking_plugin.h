#ifndef TRACKING_PLUGIN_H
#define TRACKING_PLUGIN_H

#include <QQmlExtensionPlugin>

class TrackingPlugin : public QQmlExtensionPlugin{

    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif // TRACKING_PLUGIN_H
