#-------------------------------------------------
#
# Project created by QtCreator 2013-07-01T12:33:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gun
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bullet.cpp \
    gun.cpp

HEADERS  += mainwindow.h \
    bullet.h \
    gun.h

FORMS    += mainwindow.ui
