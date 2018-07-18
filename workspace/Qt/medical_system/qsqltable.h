#ifndef QSQLTABLE_H
#define QSQLTABLE_H

#include <QDialog>
#include <QSqlTableModel>
#include "loginsystem.h"

namespace Ui {
class qsqltable;
}

class qsqltable : public QDialog
{
    Q_OBJECT

public:
    explicit qsqltable(QWidget *parent = 0);

    void SetUserTableStytle();

    ~qsqltable();

private slots:
    void on_delete2_clicked();

private:
    Ui::qsqltable *ui;

    QSqlTableModel *model;
};

#endif // QSQLTABLE_H
