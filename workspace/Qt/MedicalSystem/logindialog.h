#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = 0);
    ~loginDialog();

signals:

    void showmain();

    void showsignin();

private slots:

    void receivesignin();

    void on_loginbutton_clicked();

    void on_closebutton_clicked();

    void on_signbutton_clicked();

private:
    Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
