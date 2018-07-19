/****************************************************************************
**  Author: Wang weijian, Chen Shumin, Liu ao, Liu Shanshan, Wen Yutong    **

**  Date: 2018.7.18                                                        **
**   Version: 2.0.1                                                        **
****************************************************************************/
#include "mainwindow.h"
#include "logindialog.h"
#include "signindialog.h"
#include "qsqlconnect.h"

#include "showchart.h"
#include "showchart_2.h"
#include "showchart_3.h"
#include "AxisTag.h"

#include <QWidget>
#include <QDialog>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnection())
        return 1;

    MainWindow w;
    loginDialog log;
    signinDialog si;
    showchart s;
    showchart_2 s2;
    showchart_3 s3;

    log.show();

    QObject::connect(&log,SIGNAL(showmain()),&w,SLOT(receivelogin()),Qt::UniqueConnection);
    QObject::connect(&log,SIGNAL(showsignin()),&si,SLOT(receivelogin2()),Qt::UniqueConnection);
    QObject::connect(&si,SIGNAL(showlogin()),&log,SLOT(receivesignin()),Qt::UniqueConnection);
    QObject::connect(&w,SIGNAL(jumptochart_1()),&s,SLOT(chartsignal_1()),Qt::UniqueConnection);
    QObject::connect(&w,SIGNAL(jumptochart_2()),&s2,SLOT(chartsignal_2()),Qt::UniqueConnection);
    QObject::connect(&w,SIGNAL(jumptochart_3()),&s3,SLOT(chartsignal_3()),Qt::UniqueConnection);
    return a.exec();
}
