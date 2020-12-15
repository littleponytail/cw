#ifndef CHANGE_INFO_H
#define CHANGE_INFO_H
#include "client.h"
#include <QDialog>

namespace Ui {
class change_info;
}

class change_info : public QDialog
{
    Q_OBJECT

public:
    explicit change_info(client cur_client, QWidget *parent = nullptr);
    void change_client_info();
    ~change_info();

private slots:
    void on_pushButton_clicked();

private:
    Ui::change_info *ui;
    client cur_client;
};

#endif // CHANGE_INFO_H
