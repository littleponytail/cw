#pragma once
#ifndef DATABASE_PEOPLE_AMOUNT_H
#define DATABASE_PEOPLE_AMOUNT_H
#include "QSqlTableModel"
#include "headers.h"
#include <QDialog>

namespace Ui {
class database_people_amount;
}

class database_people_amount : public QDialog
{
    Q_OBJECT

public:
    explicit database_people_amount(QWidget *parent = nullptr);
    ~database_people_amount();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::database_people_amount *ui;
    QSqlTableModel* table1;
    void autofill();
};

#endif // DATABASE_PEOPLE_AMOUNT_H
