#pragma once
#ifndef FINDED_EXURSINSIONS_H
#define FINDED_EXURSINSIONS_H
#include"headers.h"
#include "excursion.h"
namespace Ui {
class Finded_exursinsions;
}

class Finded_exursinsions : public QDialog
{
    Q_OBJECT

public:
    explicit Finded_exursinsions(QString cur_login,excursion example, QString price_from, QString price_to, QWidget *parent = nullptr);
    ~Finded_exursinsions();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Finded_exursinsions *ui;
    QString cur_login;
};
#endif // FINDED_EXURSINSIONS_H
