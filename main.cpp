#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "mindmapview.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<MindMapView>("MindForge", 1, 0, "MindMapView");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));



    foreach(QObject *rootObject, engine.rootObjects())
    {
        auto mmv =  rootObject->findChild<MindMapView*>("mindMapView");
        if (mmv) {
            qDebug()<<"FOUND!"<<endl;
        }
    }



    //Q_ASSERT(mmv);

    return app.exec();
}
