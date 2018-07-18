#ifndef SHOWCHART_H
#define SHOWCHART_H

#include <QDialog>
#include "qcustomplot.h"
#include "AxisTag.h"
#include <QVector>

namespace Ui {
class showchart;
}

class showchart : public QDialog
{
    Q_OBJECT

public:
  explicit showchart(QWidget *parent = 0);
  ~showchart();

    //以下是新添加的程序
  double Buff[100];    //数据缓冲数组
  unsigned char CurrentData;
  //以上是新添加的程序

private slots:
  void timerSlot();

  //用于获取数据，测试用
  void ReadyShowLine();
  //

  void on_pushButton_clicked();

  void on_buttonBox_accepted();

  void chartsignal();

private:
  Ui::showchart *ui;
  QCustomPlot *mPlot;
  QPointer<QCPGraph> mGraph1;
  QPointer<QCPGraph> mGraph2;
  AxisTag *mTag1;
  AxisTag *mTag2;
  QTimer mDataTimer;

  //
   unsigned long int flag;
   //
};

#endif // SHOWCHART_H
