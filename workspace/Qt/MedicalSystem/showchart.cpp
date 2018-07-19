#include "showchart.h"
#include "ui_showchart.h"
#include <QTimer>
#include <QTime>

showchart::showchart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showchart),
    mPlot(0),
    mTag1(0)
{
    ui->setupUi(this);

    unsigned int i=0;

    for( i=0;i<100;i++)
    {
        Buff_1[i] = 0;
    }
    CurrentData=0;
    flag=0;

    mPlot = new QCustomPlot(ui->table);
    mPlot->resize(770,300);

    // configure plot to have two right axes:
    mPlot->yAxis->setTickLabels(false);
    connect(mPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), mPlot->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    mPlot->yAxis2->setVisible(true);
    mPlot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(30); // add some padding to have space for tags
    mPlot->xAxis->setLabel("time");
    mPlot->yAxis->setLabel("data");

    // create graphs:
    mGraph1 = mPlot->addGraph(mPlot->xAxis, mPlot->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph1->setPen(QPen(Qt::red));

    // create tags with newly introduced AxisTag class (see axistag.h/.cpp):
    mTag1 = new AxisTag(mGraph1->valueAxis());
    mTag1->setPen(mGraph1->pen());

    connect(&mDataTimer, SIGNAL(timeout()), this, SLOT(ReadyShowLine()));
    mDataTimer.start(80);
}

showchart::~showchart()
{
    delete ui;
}

void showchart::timerSlot()
{
    /*//以下为修改后的程序
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    mGraph1->setData(x, y);
    mGraph2->setData(x, y);
    */

    // calculate and add a new data point to each graph:
    /* mGraph1->addData(mGraph1->dataCount(), qSin(mGraph1->dataCount()/50.0)+qSin(mGraph1->dataCount()/50.0/0.3843)*0.25);
    mGraph2->addData(mGraph2->dataCount(), qCos(mGraph2->dataCount()/50.0)+qSin(mGraph2->dataCount()/50.0/0.4364)*0.15);
  */

    QVector<double> Xvalue(100);
    QVector<double> Yvalue(100);
    if(flag<=99)
    {  //当图形中不足100个点时，进入到if句里处理

        Buff_1[flag]=CurrentData;//将新数据存入缓冲区
        unsigned int i=0;
        for(i=0;i<=flag;i++)
        {
            Xvalue[i]=i;
            Yvalue[i]=Buff_1[i];

        }//分别赋值X轴，Y轴值，产生多少个实时值，就赋值多少个点
        flag++;

        mGraph1->setData(Xvalue,Yvalue);

        mPlot->xAxis->rescale();
        mGraph1->rescaleValueAxis(false, true);

        mPlot->xAxis->setRange(mPlot->xAxis->range().upper, 100, Qt::AlignRight);

        // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
        double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);
        mTag1->updatePosition(graph1Value);
        mTag1->setText(QString::number(graph1Value, 'f', 2));

        mPlot->replot();

        return;
    }

    //当实时数据超过100个时，进行以下处理
    for(int i=0;i<99;i++)
    {
        Buff_1[i]=Buff_1[i+1];
    }

    Buff_1[99]=CurrentData;
    //缓冲区整体左移，Buff[0]丢弃，Buff[99]接收新数据
    for(int i=0;i<100;i++)
    {
        Xvalue[i] = flag-(99-i);
        Yvalue[i] =Buff_1[i];
    }//X,Y轴赋满100个值，其中X轴要跟着增加

    mGraph1->setData(Xvalue,Yvalue);


    flag++;

    // make key axis range scroll with the data:
    mPlot->xAxis->rescale();
    mGraph1->rescaleValueAxis(false, true);
    mPlot->xAxis->setRange(mPlot->xAxis->range().upper, 100, Qt::AlignRight);

    // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
    double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);
    mTag1->updatePosition(graph1Value);
    mTag1->setText(QString::number(graph1Value, 'f', 2));

    mPlot->replot();
}


void  showchart::ReadyShowLine()

{

    CurrentData=CurrentData+5;

    if(CurrentData>=80) CurrentData=0;//产生锯齿波，最大值是75

    timerSlot();
}

void showchart::chartsignal_1()
{
    this->show();
}

