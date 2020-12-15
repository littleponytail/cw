#pragma once
#pragma once
#ifndef EXURSION_SHOW_H
#define EXURSION_SHOW_H
#include"headers.h"
#include "excursion.h"
namespace Ui {
class exursion_show;
}

class exursion_show : public QWidget
{
    Q_OBJECT

public:

  explicit exursion_show(QWidget *parent = nullptr);
    exursion_show( QString escountry, QString esname, QString eshotel_rate, QString espicture_path, QString esprice, QString esmeals, QWidget *parent= nullptr);
    exursion_show(QString log, excursion* showed_exursion, QWidget * parent=nullptr);
    QString getcountry_name(){return escountry;};
    float getprice(){return esprice;};
    QString gethotel_rate(){return eshotel_rate;};
    QString getname(){return esname;};
    QString getmeals(){return esmeals;};
    QString getpicture_path(){return espicture_path;};
    int get_id(){return id;}
    ~exursion_show();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
          QString escountry;
          QString esname;
          QString eshotel_rate;
          QString espicture_path;
          float esprice;
          QString esmeals;
          int id;
           QString log;
    Ui::exursion_show *ui;


};

#endif // EXURSION_SHOW_H
