#include "signindialog.h"
#include "ui_signindialog.h"
#include "qsqlconnect.h"
#include <QSqlTableModel>
#include <QSqlRecord>

signinDialog::signinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signinDialog)
{
    ui->setupUi(this);
}

signinDialog::~signinDialog()
{
    delete ui;
}

void signinDialog::on_cancelbutton_clicked()
{
    this->close();
    emit showlogin();
}

void signinDialog::on_signinbutton_clicked()
{
    QString pnewusername = ui->newname->text();
    QString pnewphonenumber = ui->newphonenum->text();
    QString pnewpassword = ui->newpassword->text();
    QString pnewpassword2 = ui->newpassword2->text();
    if((pnewusername==NULL)&&(pnewphonenumber==NULL)&&(pnewpassword==NULL))
    {
        QMessageBox::warning(this,"警告","输入不能为空",QMessageBox::Ok);
    }
    else
    {
        if(pnewpassword == pnewpassword2)
        {//如果两次密码一致，将用户信息存入数据库中
            QSqlTableModel *model = new QSqlTableModel();
            model->setTable("user");
            model->select();
            int rowNum = model->rowCount(); //获得表的行数,(读回来的rowNum是0,为上一个×××××错误×××××(加上上一句model->select();解决了这个问题)，但是数据也能插进去)
            qDebug()<<rowNum;

            int id = rowNum+1;
            model->insertRow(rowNum); //添加一行
            model->setData(model->index(rowNum,0),id);//给数据库中的ID字段赋值
            model->setData(model->index(rowNum,1),pnewusername);
            model->setData(model->index(rowNum,2),pnewphonenumber);
            model->setData(model->index(rowNum,3),pnewpassword);
            model->submitAll(); //可以直接提交
            this->close();
            emit showlogin();
        }
        else
        {//如果两次密码不一致
            QMessageBox msgBox(this);
            msgBox.setText("两次输入密码不一致，请重新输入！");
            msgBox.exec();
        }
   }


}
void signinDialog::receivelogin2()
{
    this->show();
}
