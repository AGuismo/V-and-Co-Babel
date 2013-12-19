#-------------------------------------------------
#
# Project created by QtCreator 2013-12-18T16:22:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

SOURCES += main.cpp\
        application.cpp \
    network.cpp \
    graphic.cpp

HEADERS  += application.hh \
    network.hh \
    graphic.hh \
    IGraphic.hh \
    INetwork.hh \
    IApplication.hh \
    ISignaler.hh \
    IMutex.hh
