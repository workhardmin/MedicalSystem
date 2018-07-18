#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>

namespace Ui {
class signinDialog;
}

class signinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit signinDialog(QWidget *parent = 0);
    ~signinDialog();

signals:

    void showlogin();

private slots:

    void receivelogin2();

    void on_cancelbutton_clicked();

    void on_signinbutton_clicked();

private:
    Ui::signinDialog *ui;
};

#endif // SIGNINDIALOG_H
