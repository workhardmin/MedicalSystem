#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "showchart.h"
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

void MainWindow::on_ShowChart_clicked()
{

     emit jumptochart();
}


