#pragma once
#ifndef REGISTRATION_WINDOW_H
#define REGISTRATION_WINDOW_H

#include"headers.h"

namespace Ui {
class registration_window;}

class registration_window : public QDialog
{
    Q_OBJECT
public:
   explicit registration_window(QWidget *parent = nullptr);
    ~registration_window();
signals:void cansel();
    void ok();

private slots:
   void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::registration_window *ui;

};

#endif // REGISTRATION_WINDOW_H
