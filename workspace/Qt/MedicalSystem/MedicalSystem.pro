#-------------------------------------------------
#
# Project created by QtCreator 2018-07-17T19:04:42
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = MedicalSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    signindialog.cpp \
    showchart.cpp \
    AxisTag.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    signindialog.h \
    qsqlconnect.h \
    showchart.h \
    AxisTag.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    signindialog.ui \
    showchart.ui
