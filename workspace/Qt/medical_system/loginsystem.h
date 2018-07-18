#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H
#include <QWidget>
#include <QDialog>
#include <QtSql/QSqlQuery>


class QCompleter;

namespace Ui {
class loginsystem;
}

class loginsystem : public QDialog
{
    Q_OBJECT

public:
    explicit loginsystem(QWidget *parent = 0);
    ~loginsystem();
    QCompleter *completer;

signals:

    void showmain();

    void showsignin();

    void passWordIsRight();

private slots:

    void receivesignin();

    void timerUpdate();

    void on_cancel_clicked();

    void on_login_clicked();

    void on_sign_in_clicked();

private:
    Ui::loginsystem *ui;
};

#endif // LOGINSYSTEM_H
