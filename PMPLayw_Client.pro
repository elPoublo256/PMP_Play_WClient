#-------------------------------------------------
#
# Project created by QtCreator 2017-09-26T10:57:05
#
#-------------------------------------------------

QT       += core gui
QT       +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PMPLayw_Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myclient.cpp

HEADERS  += mainwindow.h \
    myclient.h

FORMS    += mainwindow.ui
