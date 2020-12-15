#ifndef BOOK_WINDOW_H
#define BOOK_WINDOW_H
#include "client.h"
#include <QDialog>
#include "headers.h"
namespace Ui {
class book_window;
}

class book_window : public QDialog
{
    Q_OBJECT

public:
    explicit book_window(QWidget *parent = nullptr);
    book_window(QString login,int id, QString date, QWidget *parent = nullptr);
    void book();
    ~book_window();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::book_window *ui;
    int id;
    QString search_date;
    client cur_client;
};

#endif // BOOK_WINDOW_H
