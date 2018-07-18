#include "mainwindow.h"
#include "logindialog.h"
#include "signindialog.h"
#include "qsqlconnect.h"

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

    log.show();

    QObject::connect(&log,SIGNAL(showmain()),&w,SLOT(receivelogin()),Qt::UniqueConnection);
    QObject::connect(&log,SIGNAL(showsignin()),&si,SLOT(receivelogin2()),Qt::UniqueConnection);
    QObject::connect(&si,SIGNAL(showlogin()),&log,SLOT(receivesignin()),Qt::UniqueConnection);

    return a.exec();
}
