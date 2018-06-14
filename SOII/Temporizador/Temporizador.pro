TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lpthread
LIBS += -lgomp
LIBS +=  -pthread
SOURCES += main.cpp
