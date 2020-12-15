#pragma once
#ifndef CLIENT_CABINET_H
#define CLIENT_CABINET_H
#include "client.h"
#include <QDialog>

namespace Ui {
class client_cabinet;
}

class client_cabinet : public QDialog
{
    Q_OBJECT

public:
    explicit client_cabinet(QWidget *parent = nullptr);
    client_cabinet(QString login, QWidget *parent = nullptr);
    ~client_cabinet();

private slots:
    void on_pushButton_clicked();

private:
    Ui::client_cabinet *ui;
    client cur_client;
};

#endif // CLIENT_CABINET_H
