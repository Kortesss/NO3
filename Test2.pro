#-------------------------------------------------
#
# Project created by QtCreator 2018-08-15T22:29:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Test2
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x #в switch есть nullptr и это будет работать

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    derivative.cpp \
    somewindow.cpp \
    deltawin.cpp \
    mnk.cpp \
    about.cpp \
    filterfft.cpp \
    switch.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    derivative.h \
        ui_mainwindow.h \
    somewindow.h \
    deltawin.h \
    mnk.h \
    about.h \
    filterfft.h \
    switch.h

FORMS    += mainwindow.ui \
    somewindow.ui \
    deltawin.ui \
    about.ui \
    filterfft.ui

RESOURCES += \
    source.qrc
