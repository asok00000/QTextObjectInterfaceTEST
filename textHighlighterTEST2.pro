TEMPLATE = app

QT += qml gui quick widgets

SOURCES += main.cpp \
    highlighter.cpp \
    framedtextattr.cpp

RESOURCES += qml.qrc \
    qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    highlighter.h \
    framedtextattr.h
