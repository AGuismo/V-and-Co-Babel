# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

# This is a reminder that you are using a generated .pro file.
# Remove it when you are finished editing this file.
message("You are running qmake on a generated .pro file. This may not work!")


HEADERS += ./Graphic.h  \
            ./AGraphic.hh   \
        ./AApplication.hh   \
        ./ANetwork.hh       \
        ./Function.hpp \
    TCPNetwork.hh \
    Application.hh \
    IApplication.hh \
    ConnectWindow.h
SOURCES += ./Graphic.cpp \
    ./main.cpp \
    ./AGraphic.cpp \
    ANetwork.cpp \
    TCPNetwork.cpp \
    Application.cpp \
    ConnectWindow.cpp
FORMS += ./Graphic.ui \
    ConnectWindow.ui
RESOURCES += Graphic.qrc