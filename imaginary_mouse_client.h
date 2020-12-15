#pragma once
#ifndef IMAGINARY_MOUSE_CLIENT_H
#define IMAGINARY_MOUSE_CLIENT_H
#include"headers.h"

namespace Ui {
class Imaginary_mouse_client;
}

class Imaginary_mouse_client : public QDialog
{
    Q_OBJECT

public:
    explicit Imaginary_mouse_client(QDialog *parent = nullptr);
     Imaginary_mouse_client(QString client_login, QDialog *parent = nullptr);
     void search();
    ~Imaginary_mouse_client();

private slots:


    void on_pushButton_3_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_27_clicked();

private:
    Ui::Imaginary_mouse_client *ui;
    QString client_login;
    int id;
};

#endif // IMAGINARY_MOUSE_CLIENT_H
