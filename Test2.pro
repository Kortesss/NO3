#-------------------------------------------------
#
# Project created by QtCreator 2018-08-15T22:29:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Test2
TEMPLATE = app

#-------------------------------------------------
#Часть классов/методов могут быть объявлены устаревшими/нежелательными.
#Такие классы/методы являются легаси-кодом,
#т.е. предоставляются для поддержки ранее написанной кодовой базы, и нежелательны для новых проектов.
#Эта директива приведет к тому, что при использовании таких методов/классов при сборке
#будут вываливаться в консоль сборки предупреждения от компилятора, что код нежелательный.
DEFINES += QT_DEPRECATED_WARNINGS
#-------------------------------------------------

#-------------------------------------------------
#Для того, чтобы декларировать, что указатель ни на что не указывает, до принятия стандарта C++11 использовался макрос NULL или значение 0,
#что приводило к проблемам, так как допускалось неявное строковые или целочисленные преобразования.
#Можно было получить "сюрпризы" весьма неприятного свойства, nullptr гарантированно означает, что указатель ни на что не указывает, и никаких преобразований не будет.
CONFIG += c++11
#Означает, что в проекте используются возможности, характерные для для стандарта c++11, например, тот самый nullptr и лямбды.
#В самых свежих версиях Qt эта версия используется по умолчанию.
#-------------------------------------------------

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    derivative.cpp \
    mnk.cpp \
    extrem_simple.cpp \
    correl_analysis.cpp \
    fdistribution.cpp \
    dispers_analysis.cpp \
    grDerivative.cpp \
    filterDFT.cpp \
    deltaSignal.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    derivative.h \
        ui_mainwindow.h \
    mnk.h \
    extrem_simple.h \
    correl_analysis.h \
    fdistribution.h \
    dispers_analysis.h \
    grDerivative.h \
    filterDFT.h \
    deltaSignal.h

FORMS    += mainwindow.ui \
    correl_analysis.ui \
    dispers_analysis.ui \
    grDerivative.ui \
    filterDFT.ui \
    deltaSignal.ui

RESOURCES += \
    source.qrc
