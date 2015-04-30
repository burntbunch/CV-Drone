! include( ../../common.pri ) {
    error("Couldn't find the common.pri file!")
}

INCLUDEPATH += "../logic"

CONFIG += link_pkgconfig

PKGCONFIG += opencv

HEADERS += \ 
    ObjectDetector.h

SOURCES += \ 
    ObjectDetector.cpp
