#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T13:28:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Asteroids
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    mainship.cpp \
    bullet.cpp

HEADERS  += mainwindow.h \
    scene.h \
    mainship.h \
    bullet.h \
    quickmath.h

RESOURCES += \
    resources.qrc
