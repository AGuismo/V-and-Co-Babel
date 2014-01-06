TEMPLATE = app
TARGET = NewBabelClient
QT += core multimedia network webkit widgets gui webkitwidgets multimediawidgets
CONFIG += debug
DEFINES += QT_MULTIMEDIA_LIB QT_MULTIMEDIAWIDGETS_LIB QT_NETWORK_LIB QT_WEBKITWIDGETS_LIB QT_WIDGETS_LIB
INCLUDEPATH += $$PWD \
    ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug \
    ../../../serializer/include \
    ../../../protocol/API       \
    ../../../protocol/include   \
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(NewBabelClient.pri)

LIBS += -lopus -lportaudio

SOURCES +=

