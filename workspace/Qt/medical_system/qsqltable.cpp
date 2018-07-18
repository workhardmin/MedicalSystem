#include "qsqltable.h"
#include "ui_qsqltable.h"
#include "loginsystem.h"
#include "qsqldatabase.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>


static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("waterData.db");
    if(!db.open()) return false;
    QSqlQuery query;
    query.exec(QObject::tr("create table user (id int, name vchar primary key,phone vchar,passWord vchar)"));
    /*query.exec(QObject::tr("insert into user values (1,'Tom',123456,999)"));
    query.exec(QObject::tr("insert into user values (2,'Lily',123444,888)"));
    query.exec(QObject::tr("insert into user values (3,'Lucy',456456,666)"));
    query.exec(QObject::tr("insert into user values (4,'小强',789789,555)"));*/
    return true;
}
qsqltable::qsqltable(QWidget *parent) :QDialog(parent),
    ui(new Ui::qsqltable)
{
    ui->setupUi(this);
    bool sqlState = createConnection();
    if(sqlState){
        qDebug()<<"The database is already open !";
    }
    else{
        qDebug()<<"The database open failed !";
    }

    model = new QSqlTableModel(this);
    model->setTable("user");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //选取整个表的所有行
    model->removeColumn(4); //不显示name属性列,如果这时添加记录，则该属性的值添加不上
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //使其不可编辑
    SetUserTableStytle();//设置tableview的样式
}

qsqltable::~qsqltable()
{
    delete ui;
}

void qsqltable::on_delete2_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    qDebug()<<model->rowCount();
    //获取选中的行
    model->removeRow(curRow);
    //删除该行
    int ok = QMessageBox::warning(this,tr("删除当前行!"),tr("你确定""删除当前行吗？"),
                         QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
       model->revertAll(); //如果不删除，则撤销
    }
    else model->submitAll(); //否则提交，在数据库中删除该行
}



void qsqltable::updateUserTable()
{
    model->setTable("user");   //重新关联表
    model->removeColumn(4);
    model->select();   //这样才能再次显示整个表的内容
    SetUserTableStytle();//设置用户表格式，如居中显示等
//    qDebug()<<model->rowCount();
}

void qsqltable::SetUserTableStytle()
{
    model->setHeaderData(0,Qt::Horizontal,tr("编号"));//设置表头显示内容
    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));//设置表头显示内容
    model->setHeaderData(2,Qt::Horizontal,tr("手机号"));
    model->setHeaderData(3,Qt::Horizontal,tr("密码"));
    ui->tableView->verticalHeader()->setVisible(false);//禁止显示垂直方向表头
    ui->tableView->setColumnWidth(0,ui->tableView->width()/2);//设置列宽度
    ui->tableView->setColumnWidth(1,ui->tableView->width()/2);//设置列宽度
}
