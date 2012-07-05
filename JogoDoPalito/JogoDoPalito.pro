#-------------------------------------------------
#
# Project created by QtCreator 2012-07-04T21:01:01
#
#-------------------------------------------------

QT       += core gui network

TARGET = JogoDoPalito
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    basketsocket.cpp \
    player.cpp \
    connectiondialog.cpp

HEADERS  += mainwindow.h \
    basketsocket.h \
    player.h \
    connectiondialog.h

FORMS    += mainwindow.ui \
    connectiondialog.ui
