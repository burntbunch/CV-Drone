TEMPLATE = subdirs

SUBDIRS +=  logic \
            logic/command \
            logic/navdata \
            logic/video \
            gui \
            test

SUBDIRS += build

CONFIG += ordered
