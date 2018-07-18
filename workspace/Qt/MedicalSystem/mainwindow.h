/****************************************************************************
**  Author: Wang weijian, Chen Shumin, Liu ao, Liu Shanshan, Wen Yutong    **

**  Date: 2018.7.18                                                        **
**   Version: 2.0.1                                                        **
****************************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "AxisTag.h"
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void receivelogin();

    void on_ShowChart_clicked();
signals:
    void  jumptochart();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
