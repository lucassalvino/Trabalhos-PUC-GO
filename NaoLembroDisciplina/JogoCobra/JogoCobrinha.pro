TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += thread

SOURCES += main.cpp \
    mapa.cpp \
    jogador.cpp \
    interfacelogica.cpp \
    itemmovel.cpp \
    modotexto.cpp \
    data.cpp \
    utilidades.cpp \
    niveis.cpp \
    avancarnivel.cpp

HEADERS += \
    mapa.h \
    jogador.h \
    interfacelogica.h \
    itemmovel.h \
    modotexto.h \
    data.h \
    utilidades.h \
    niveis.h \
    avancarnivel.h

DISTFILES += \
    README.txt
