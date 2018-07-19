#ifndef SHOWCHART_3_H
#define SHOWCHART_3_H

#include <QDialog>
#include "qcustomplot.h"
#include "AxisTag.h"
#include <QVector>

namespace Ui {
class showchart_3;
}

class showchart_3 : public QDialog
{
    Q_OBJECT

public:
    explicit showchart_3(QWidget *parent = 0);
    ~showchart_3();

    //以下是新添加的程序
  double Buff_3[100];    //数据缓冲数组
  unsigned char CurrentData;
  //以上是新添加的程序

private slots:
  void timerSlot();

  //用于获取数据，测试用
  void ReadyShowLine();
  //

  void on_pushButton_clicked();

  void on_buttonBox_accepted();

  void chartsignal_3();

private:
    Ui::showchart_3 *ui;
    QCustomPlot *mPlot;
    QPointer<QCPGraph> mGraph1;
    AxisTag *mTag1;
    QTimer mDataTimer;

    //
     unsigned long int flag;
     //
};

#endif // SHOWCHART_3_H
