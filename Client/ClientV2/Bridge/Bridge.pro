#-------------------------------------------------
#
# Project created by QtCreator 2013-12-27T10:27:43
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bridge
TEMPLATE = app


SOURCES += main.cpp \
    QTBridge.cpp \
    AudioBridge.cpp \
    audio.cpp \
    FakeMenu.cpp

HEADERS  += \
    Abridge.hh \
    QTBridge.h \
    AudioBridge.hh \
    audio.h \
    FakeMenu.h

FORMS += \
    audio.ui \
    FakeMenu.ui
