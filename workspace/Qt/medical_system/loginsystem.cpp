#include "loginsystem.h"
#include "ui_loginsystem.h"
#include "qsqltable.h"
#include "qsql.h"
#include <qmessagebox.h>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QString>
#include <qdebug.h>
#include <QTimer>
#include <QDateTime>
#include <QSqlTableModel>

loginsystem::loginsystem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginsystem)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);//关联定时器溢出信号和相应的槽函数
    connect(timer,&QTimer::timeout,this, &loginsystem::timerUpdate);
    timer->start(1000);

}

loginsystem::~loginsystem()
{
    qDebug()<<__FUNCTION__<<"is running";
    delete ui;
}

void loginsystem::timerUpdate()
{
   QDateTime time = QDateTime::currentDateTime();
   QString str = time.toString("yyyy年MM月dd日 hh:mm:ss dddd");
   ui->time->setText(str);
}

void loginsystem::on_cancel_clicked()
{
    this->close();
}

void loginsystem::on_login_clicked()
{

    QString pusername = ui->username->text();
    QString pphonenumber = ui->phonenumber->text();
    QString ppassword = ui->password->text();
    if((pusername==NULL)&&(pphonenumber==NULL)&&(ppassword==NULL))
    {
        QMessageBox::warning(this,"警告","输入不能为空",QMessageBox::Ok);
    }
    else
    {   QSqlTableModel model;
        model.setTable("user");
        model.select();
        int userCnt = 0;
        for(int i=0;i<model.rowCount();++i)
        {
            QSqlRecord record = model.record(i);
            QString name = record.value("name").toString();
            QString phone = record.value("phone").toString();
            QString passWord = record.value("passWord").toString();
            qDebug()<<name<<passWord<<__FUNCTION__;
            if(pusername == name)
            {
                qDebug()<<"用户名正确!";
                if(pphonenumber == phone)
                {
                    qDebug()<<"手机号正确!";
                    if(ppassword == passWord)
                    {
                        //emit passWordIsRight();//密码正确传信号给Mainwindow,从而显示参数设置界面
                        this->close();

                        emit showmain();
                    }
                    else
                    {
                        QMessageBox msgBox(this);
                        msgBox.setText("The password is wrong.");
                        msgBox.exec();
                    }
                }
                else
                {
                    QMessageBox msgBox(this);
                    msgBox.setText("The phoen number is wrong.");
                    msgBox.exec();
                }
            userCnt++;
            }
        }
        if(!userCnt)
        {
            QMessageBox msgBox(this);
            msgBox.setText("该用户不存在！");
            msgBox.exec();
        }
    }


}

void loginsystem::on_sign_in_clicked()
{
    this->close();
    emit showsignin();
}
void loginsystem::receivesignin()
{
    this->show();
}
