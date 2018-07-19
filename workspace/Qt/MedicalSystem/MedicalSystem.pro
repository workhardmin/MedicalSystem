#-------------------------------------------------
#
# Project created by QtCreator 2018-07-17T19:04:42
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = MedicalSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    signindialog.cpp \
    showchart.cpp \
    AxisTag.cpp \
    qcustomplot.cpp \
    showchart_2.cpp \
    showchart_3.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    signindialog.h \
    qsqlconnect.h \
    showchart.h \
    AxisTag.h \
    qcustomplot.h \
    showchart_2.h \
    showchart_3.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    signindialog.ui \
    showchart.ui \
    showchart_2.ui \
    showchart_3.ui
