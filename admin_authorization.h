#pragma once
#ifndef ADMIN_AUTHORIZATION_H
#define ADMIN_AUTHORIZATION_H
#include"headers.h"

namespace Ui {
class admin_authorization;
}

class admin_authorization : public QDialog
{
    Q_OBJECT

public:
    explicit admin_authorization(QWidget *parent = nullptr);
    ~admin_authorization();

private slots:
    void on_pushButton_clicked();

private:
    Ui::admin_authorization *ui;
};

#endif // ADMIN_AUTHORIZATION_H
