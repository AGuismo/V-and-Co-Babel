#-------------------------------------------------
#
# Project created by QtCreator 2013-12-27T10:27:43
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bridge
TEMPLATE = app

unix:
{
PRE_TARGETDEPS += "/usr/lib64/libportaudio.so"
PRE_TARGETDEPS += "/usr/lib64/libopus.so.0"
LIBS += -L/usr/lib64 -lportaudio -lopus
}
win32:LIBS += ""

SOURCES += main.cpp \
    QTBridge.cpp \
    AudioBridge.cpp \
    audio.cpp \
    FakeMenu.cpp \
    PAudioStream.cpp \
    PAudioBuffer.cpp \
    OpAudioCodec.cpp \
    MyApplication.cpp

HEADERS  += \
    Abridge.hh \
    QTBridge.h \
    AudioBridge.hh \
    audio.h \
    FakeMenu.h \
    PAudioStream.hh \
    PAudioBuffer.hh \
    OpAudioCodec.hh \
    IAudioStream.hh \
    IAudioCodec.hh \
    AudioParams.hh \
    MyApplication.hh

FORMS += \
    audio.ui \
    FakeMenu.ui
