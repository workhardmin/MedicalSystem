#-------------------------------------------------
#
# Project created by QtCreator 2018-07-16T17:10:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = medical_system
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginsystem.cpp \
    signin.cpp \
    qsqltable.cpp

HEADERS  += mainwindow.h \
    loginsystem.h \
    signin.h \
    qsqltable.h

FORMS    += mainwindow.ui \
    loginsystem.ui \
    signin.ui \
    qsqltable.ui
