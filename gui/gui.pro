! include( ../common.pri ) {
    error("Couldn't find the common.pri file!")
}

QMAKE_CFLAGS_WARN_OFF -= -Wunused-parameter

QT += gui widgets

INCLUDEPATH += "../logic"
INCLUDEPATH += "../logic/navdata"
INCLUDEPATH += "../logic/command"
INCLUDEPATH += "../logic/video"

SOURCES +=\
    CommandDebugWindow.cpp \
    MainWindow.cpp \
    NavdataDebugWindow.cpp \
    OpenCVDebugWindow.cpp \
    VideoSettingsWindow.cpp \
    ControlWindow.cpp

HEADERS  += \
    CommandDebugWindow.h \
    MainWindow.h \
    NavdataDebugWindow.h \
    OpenCVDebugWindow.h \
    VideoSettingsWindow.h \
    ControlWindow.h

FORMS    += \
    CommandDebugWindow.ui \
    MainWindow.ui \
    NavdataDebugWindow.ui \
    OpenCVDebugWindow.ui \
    VideoSettingsWindow.ui \
    ControlWindow.ui
