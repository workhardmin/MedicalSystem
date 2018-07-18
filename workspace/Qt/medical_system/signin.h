#ifndef SIGNIN_H
#define SIGNIN_H
#include <QWidget>
#include <QDialog>
#include <QtSql/QSqlQuery>

namespace Ui {
class signin;
}

class signin : public QDialog
{
    Q_OBJECT

public:
    explicit signin(QWidget *parent = 0);
    ~signin();


signals:
    void AddUserSuccess();
    void showlogin();

private slots:
    void receivelogin2();
    void on_newsignin_clicked();

private:
    Ui::signin *ui;
};

#endif // SIGNIN_H
