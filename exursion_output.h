#ifndef EXURSION_OUTPUT_H
#define EXURSION_OUTPUT_H

#include <QDialog>

namespace Ui {
class exursion_output;
}

class exursion_output : public QDialog
{
    Q_OBJECT

public:
    explicit exursion_output(QWidget *parent = nullptr);
    exursion_output(QString client_login,int id, QWidget *parent = nullptr);
    int get_id();
    ~exursion_output();

private slots:


    void on_first_date_clicked();

    void on_second_date_clicked();

    void on_third_date_clicked();

    void on_fouth_date_clicked();

    void on_fifth_date_clicked();

    void on_sixth_date_clicked();

    void on_seventh_date_clicked();

    void on_eighth_date_clicked();

    void on_ninth_date_clicked();

    void on_tenth_date_clicked();

    void on_eleventh_date_clicked();

    void on_twelth_date_clicked();

    void on_thirteen_date_clicked();

    void on_fourteenht_date_clicked();

    void on_fifteenth_date_clicked();

    void on_sixteenth_date_clicked();

    void on_seventeenth_date_clicked();

    void on_eighteenth_date_clicked();

    void on_nineteenth_date_clicked();

    void on_twenteenth_date_clicked();

private:
    Ui::exursion_output *ui;
    int id;
    QString login;
};

#endif // EXURSION_OUTPUT_H
