#-------------------------------------------------
#
# Project created by QtCreator 2018-08-15T22:29:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Test2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    derivative.cpp \
    somewindow.cpp \
    deltawin.cpp \
    mnk.cpp \
    loadfile.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    derivative.h \
        ui_mainwindow.h \
    somewindow.h \
    deltawin.h \
    mnk.h \
    loadfile.h

FORMS    += mainwindow.ui \
    somewindow.ui \
    deltawin.ui

RESOURCES += \
    source.qrc
