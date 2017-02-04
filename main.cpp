#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "mindmapview.h"
#include "mindmaploader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<MindMapView>("MindForge", 1, 0, "MindMapView");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    MindMapNode *rootNode = MindMapLoader::load();

    rootNode->setParent(&engine);

    foreach(QObject *rootObject, engine.rootObjects())
    {
        auto mmv =  rootObject->findChild<MindMapView*>("mindMapView");
        if (mmv) {
            mmv->setRootNode(rootNode);
        }
    }

    return app.exec();
}
