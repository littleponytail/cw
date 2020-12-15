#ifndef DATABASE_BOOK_H
#define DATABASE_BOOK_H
#include "QSqlTableModel"
#include <QDialog>

namespace Ui {
class database_book;
}

class database_book : public QDialog
{
    Q_OBJECT

public:
    explicit database_book(QWidget *parent = nullptr);
    ~database_book();

private slots:
    void on_pushButton_clicked();

private:
    Ui::database_book *ui;
    QSqlTableModel* table;
};

#endif // DATABASE_BOOK_H
