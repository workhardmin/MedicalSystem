#include "mainwindow.h"
#include "loginsystem.h"
#include "qsqltable.h"
#include <QApplication>
#include "qsql.h"
#include "signin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    loginsystem log;
    signin si;

    log.show();

    QObject::connect(&log,SIGNAL(showmain()),&w,SLOT(receivelogin()),Qt::UniqueConnection);
    QObject::connect(&log,SIGNAL(showsignin()),&si,SLOT(receivelogin2()),Qt::UniqueConnection);
    QObject::connect(&si,SIGNAL(showlogin()),&log,SLOT(receivesignin()),Qt::UniqueConnection);


    return a.exec();


}
