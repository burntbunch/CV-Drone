! include( ../common.pri ) {
    error("Couldn't find the common.pri file!")
}

HEADERS +=  \
	CuteService.h \
	CommandService.h \
        NavdataService.h \
        VideoService.h \
        ConfigFile.h \
    CVDrone.h

SOURCES +=  \
    	CuteService.cpp \
	CommandService.cpp \
        NavdataService.cpp \
        VideoService.cpp \
        ConfigFile.cpp \
    CVDrone.cpp

INCLUDEPATH +=  "command/" \
                "navdata/"

LIBS += -L"command/" \
        -L"navdata/" \
        -lcommand -lnavdata
