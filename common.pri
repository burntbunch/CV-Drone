#Includes common configuration for all subdirectory .pro files.
INCLUDEPATH += . ..

QT += core network

TEMPLATE = lib

CONFIG += staticlib

CONFIG += c++11

# The following keeps the generated files at least somewhat separate
# from the source files.
UI_DIR = uics
MOC_DIR = mocs
OBJECTS_DIR = objs
