#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "showchart.h"
#include "showchart_2.h"
#include "showchart_3.h"
#include "AxisTag.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket();
    QObject::connect(socket, &QTcpSocket::readyRead, this, &MainWindow::socket_Read_Data);
    QObject::connect(socket, &QTcpSocket::disconnected, this, &MainWindow::socket_Disconnected);
    ui->sendButton->setEnabled(false);
    ui->IP->setText("127.0.0.1");
    ui->PORT->setText("6666");
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ConnectButton_clicked()
{
    if(ui->ConnectButton->text() == tr("连接"))
    {
        QString IP;
        int port;
        //获取IP地址
        IP = ui->IP->text();
        //获取端口号
        port = ui->PORT->text().toInt();
        //取消已有的连接
        socket->abort();
        //连接服务器
        socket->connectToHost(IP, port);

        //等待连接成功
        if(!socket->waitForConnected(30000))
        {
               qDebug() << "Connection failed!";
               return;
         }
         qDebug() << "Connect successfully!";
         //发送按键使能
         ui->sendButton->setEnabled(true);
         //修改按键文字
         ui->ConnectButton->setText("断开连接");
    }
    else
    {
        //断开连接
        socket->disconnectFromHost();
        //修改按键文字
        ui->ConnectButton->setText("连接");
        ui->sendButton->setEnabled(false);
    }
}

void MainWindow::on_sendButton_clicked()
{
    qDebug() << "Send: " << ui->SendData->text();
     //获取文本框内容并以ASCII码形式发送
    socket->write(ui->SendData->text().toLatin1());
    socket->flush();
}
void MainWindow::socket_Read_Data()
{
    QByteArray buffer;
    //读取缓冲区数据
    buffer = socket->readAll();
    if(!buffer.isEmpty())
    {
        QString str = ui->ReceiveData->toPlainText();
        str+=tr(buffer);
        //刷新显示
        ui->ReceiveData->setText(str);
    }
}



void MainWindow::socket_Disconnected()
{
    //发送按键失能
    ui->sendButton->setEnabled(false);
    //修改按键文字
    ui->ConnectButton->setText("连接");
    qDebug() << "Disconnected!";
}




void MainWindow::receivelogin()
{
    this->show();
}
//进入子界面，显示第一张图表
void MainWindow::on_ShowChart_clicked()
{
     emit jumptochart_1();
}
//进入子界面，显示第二张图表
void MainWindow::on_showchart_2_clicked()
{
    emit jumptochart_2();
}
//进入子界面，显示第三张图表
void MainWindow::on_showchart_3_clicked()
{
    emit jumptochart_3();
}

