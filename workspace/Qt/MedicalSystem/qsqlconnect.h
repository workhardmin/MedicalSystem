#ifndef QSQLCONNECT
#define QSQLCONNECT
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>


static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("waterData.db");
    if(!db.open())
    {
        qDebug()<<"The database cannot be opened !";
        return false;
    }
    QSqlQuery query;
    query.exec(QObject::tr("create table user (id int, name vchar primary key,phone vchar,passWord vchar)"));
    /*query.exec(QObject::tr("insert into user values (1,'Tom',123456,999)"));
    query.exec(QObject::tr("insert into user values (2,'Lily',123444,888)"));
    query.exec(QObject::tr("insert into user values (3,'Lucy',456456,666)"));
    query.exec(QObject::tr("insert into user values (4,'小强',789789,555)"));*/
    return true;
}


#endif // QSQLCONNECT

