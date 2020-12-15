#pragma once
#ifndef ADMIN_MENU_H
#define ADMIN_MENU_H

#include"headers.h"
namespace Ui {
class admin_menu;
}

class admin_menu : public QDialog
{
    Q_OBJECT

public:
    explicit admin_menu(QWidget *parent = nullptr);
    ~admin_menu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::admin_menu *ui;
};

#endif // ADMIN_MENU_H
