! include( ../../common.pri ) {
    error("Couldn't find the common.pri file!")
}

HEADERS +=  CuteCommand.h \
            PCMDCommand.h \
            FTRIMCommand.h \
    REFCommand.h \
    PCMD_MAGCommand.h \
    COMWDGCommand.h \
    CONFIG_IDSCommand.h \
    CALIBCommand.h \
    CONFIGCommand.h \ 
    PMODECommand.h

SOURCES +=  CuteCommand.cpp \
            PCMDCommand.cpp \
            FTRIMCommand.cpp \
    REFCommand.cpp \
    PCMD_MAGCommand.cpp \
    COMWDGCommand.cpp \
    CONFIG_IDSCommand.cpp \
    CALIBCommand.cpp \
    CONFIGCommand.cpp \ 
    PMODECommand.cpp
