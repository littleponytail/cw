#pragma once
#ifndef DATABASE_EXCURSION_H
#define DATABASE_EXCURSION_H
#include "QSqlTableModel"
#include <QDialog>

namespace Ui {
class Database_excursion;
}

class Database_excursion : public QDialog
{
    Q_OBJECT

public:
    explicit Database_excursion(QWidget *parent = nullptr);
    void add_row ();
    void delete_row();
    void save_changes();
    ~Database_excursion();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Database_excursion *ui;
    QSqlTableModel* table;
};

#endif // DATABASE_EXCURSION_H
