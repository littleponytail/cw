#pragma once
#ifndef AUTHORIZATION_WINDOW_H
#define AUTHORIZATION_WINDOW_H
#include "registration_window.h"
#include <QMainWindow>
#include "headband.h"

QT_BEGIN_NAMESPACE
namespace Ui { class authorization_window; }
QT_END_NAMESPACE

class authorization_window : public QMainWindow
{
    Q_OBJECT

public:
    authorization_window(QWidget *parent = nullptr);
    ~authorization_window();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();


    void on_authorization_clicked();

private:
    Ui::authorization_window *ui;
    registration_window *Registrationwindow;
    HeadBand *headbandwindow;
};
#endif // AUTHORIZATION_WINDOW_H
