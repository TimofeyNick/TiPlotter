#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "TiPlotterItem.h"

int main(int argc, char *argv[])
{
#ifdef Q_OS_WIN
    // Select between OpenGL and OpenGL ES (Angle)
    //QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    QCoreApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<TiPlotterItem>("TiPlotterItem", 1, 0, "TiPlotterItem");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
