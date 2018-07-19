#ifndef SHOWCHART_2_H
#define SHOWCHART_2_H

#include <QDialog>
#include "qcustomplot.h"
#include "AxisTag.h"
#include <QVector>

namespace Ui {
class showchart_2;
}

class showchart_2 : public QDialog
{
    Q_OBJECT

public:
  explicit showchart_2(QWidget *parent = 0);
  ~showchart_2();

    //以下是新添加的程序
  double Buff_2[100];    //数据缓冲数组
  unsigned char CurrentData;
  //以上是新添加的程序

private slots:
  void timerSlot();

  //用于获取数据，测试用
  void ReadyShowLine();
  //

  void on_pushButton_clicked();

  void on_buttonBox_accepted();

  void chartsignal_2();

private:
  Ui::showchart_2 *ui;
  QCustomPlot *mPlot;
  QPointer<QCPGraph> mGraph1;
  AxisTag *mTag1;
  QTimer mDataTimer;

  //
   unsigned long int flag;
   //
};

#endif // SHOWCHART_2_H
