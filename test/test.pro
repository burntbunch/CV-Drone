! include( ../common.pri ) {
    error("Couldn't find the common.pri file!")
}

HEADERS +=  NavdataTester.h \
            VideoTester.h

SOURCES +=  NavdataTester.cpp \
            VideoTester.cpp
