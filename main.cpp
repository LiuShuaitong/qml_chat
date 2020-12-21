#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "manager/Manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Manager manager;
    QQmlApplicationEngine engine;

    manager.registQMLEngine(engine);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    manager.registQMLObject(engine.rootObjects().first());

    return app.exec();
}
