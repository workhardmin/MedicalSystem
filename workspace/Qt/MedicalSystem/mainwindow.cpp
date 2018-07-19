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
}

MainWindow::~MainWindow()
{
    delete ui;
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
