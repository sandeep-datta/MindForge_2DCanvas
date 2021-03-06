QT += qml quick

CONFIG += c++11

SOURCES += main.cpp \
    mindmapview.cpp \
    mindmapnode.cpp \
    mindmaploader.cpp \
    diagnostics.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mindmapview.h \
    mindmapnode.h \
    mindmaploader.h \
    diagnostics.h

DISTFILES += \
    TODO.txt
