#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginsystem.h"
#include "signin.h"
#include <QStackedLayout>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
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
