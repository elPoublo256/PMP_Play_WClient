#-------------------------------------------------
#
# Project created by QtCreator 2017-09-26T10:57:05
#
#-------------------------------------------------

QT       += core gui
QT       +=network
QT       += multimedia #sudo apt-get install qtmultimedia5-dev
QT       +=xml
QT       += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PMPLayw_Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myclient.cpp \
    start.cpp \
    createuser.cpp \
    pmp_player.cpp \
    treck.cpp

HEADERS  += mainwindow.h \
    myclient.h \
    start.h \
    createuser.h \
    pmp_player.h \
    treck.h

FORMS    += mainwindow.ui \
    start.ui \
    createuser.ui \
    pmp_player.ui
