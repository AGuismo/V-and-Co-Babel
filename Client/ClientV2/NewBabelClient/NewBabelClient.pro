TEMPLATE = app
TARGET = NewBabelClient
QT += core multimedia network webkit widgets gui webkitwidgets multimediawidgets xml
CONFIG += debug
DEFINES += QT_DLL QT_MULTIMEDIA_LIB QT_MULTIMEDIAWIDGETS_LIB QT_NETWORK_LIB QT_WEBKITWIDGETS_LIB QT_WIDGETS_LIB
win32
{
    DESTDIR = ./Win32/Debug
    DEFINES += WIN64
}
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug \
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(NewBabelClient.pri)
