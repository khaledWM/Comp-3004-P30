#-------------------------------------------------
#
# Project created by QtCreator 2021-04-01T20:55:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Comp-3004-P30
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        battery.cpp \
        button.cpp \
        cpu.cpp \
        display.cpp \
        frequency.cpp \
        frequencypage.cpp \
        historypage.cpp \
        main.cpp \
        mainmenupage.cpp \
        mainwindow.cpp \
        noimplementation.cpp \
        page.cpp \
        powerlevel.cpp \
        programspage.cpp \
        startpage.cpp \
        therapypage.cpp

HEADERS += \
        battery.h \
        button.h \
        cpu.h \
        display.h \
        frequency.h \
        frequencypage.h \
        historypage.h \
        mainmenupage.h \
        mainwindow.h \
        noimplementation.h \
        page.h \
        powerlevel.h \
        programspage.h \
        startpage.h \
        therapypage.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
