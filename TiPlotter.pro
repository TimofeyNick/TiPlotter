TEMPLATE = app

QT += qml quick
INCLUDEPATH += src
DEPENDPATH += src
QML_IMPORT_PATH =

include(libqnanopainter/include.pri)
include(tinyexpr/tinyexpr.pri)
include(deployment.pri)

RESOURCES += \
    $$PWD/qml/qml.qrc
SOURCES += \
    $$PWD/src/main.cpp \
    src/TiPlotterItem.cpp \
    src/TiPlotterPainter.cpp
HEADERS += \
    src/TiPlotterPainter.h \
    src/TiPlotterItem.h
