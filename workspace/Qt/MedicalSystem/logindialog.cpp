#include "logindialog.h"
#include "ui_logindialog.h"
#include "qsqlconnect.h"
#include <QSqlTableModel>
#include <QSqlRecord>

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_loginbutton_clicked()
{
    QString pusername = ui->name->text();
    QString pphonenumber = ui->phonenum->text();
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

void loginDialog::on_closebutton_clicked()
{
    this->close();
}

void loginDialog::on_signbutton_clicked()
{
    this->close();
    emit showsignin();
}
void loginDialog::receivesignin()
{
    this->show();
}
