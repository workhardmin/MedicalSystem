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


    log.show();
   // if(w.exec()==QDialog::Accepted)
   // {
   //     s.show();
   // }

    QObject::connect(&log,SIGNAL(showmain()),&w,SLOT(receivelogin()),Qt::UniqueConnection);
    QObject::connect(&log,SIGNAL(showsignin()),&si,SLOT(receivelogin2()),Qt::UniqueConnection);
    QObject::connect(&si,SIGNAL(showlogin()),&log,SLOT(receivesignin()),Qt::UniqueConnection);
    QObject::connect(&w,SIGNAL(jumptochart()),&s,SLOT(chartsignal()),Qt::UniqueConnection);
    return a.exec();
}
