#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T17:01:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MotorDeBusca
TEMPLATE = app


SOURCES += main.cpp\
        janelaprincipal.cpp \
    atualizar.cpp \
    nodoc.cpp \
    documento.cpp \
    palavradocumento.cpp \
    documentopalavra.cpp \
    tabelahash.cpp \
    excecaonaotratada.cpp \
    interface.cpp \
    ajuda.cpp \
    retorno.cpp

HEADERS  += janelaprincipal.h \
    atualizar.h \
    nodoc.h \
    documento.h \
    palavradocumento.h \
    documentopalavra.h \
    defines.h \
    tabelahash.h \
    hahshfuncoes.h \
    nodoc.hpp \
    tabelahash.hpp \
    excecaonaotratada.h \
    interface.h \
    ajuda.h \
    retorno.h \
    ordenar.h

FORMS    += janelaprincipal.ui \
    atualizar.ui \
    excecaonaotratada.ui \
    ajuda.ui

RESOURCES += \
    dados.qrc
