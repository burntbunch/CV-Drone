TEMPLATE = app

QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter

QT += core network gui widgets
CONFIG += c++11

CONFIG += link_pkgconfig

PKGCONFIG += opencv

SOURCES += main.cpp \ 
           provision.cpp

INCLUDEPATH +=  ../logic \
                ../logic/command \
                ../logic/navdata \
                ../logic/video \
                ../gui \
                ../test

LIBS += -L"../logic" \
        -L"../logic/command" \
        -L"../logic/navdata" \
        -L"../logic/video" \
        -L"../gui" \
        -L"../test" \
        -llogic -lcommand -lnavdata -lvideo -lgui -ltest


TARGET = ../CvDrone
