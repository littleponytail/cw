#include "database_book.h"
#include "ui_database_book.h"

database_book::database_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::database_book)
{
       this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
     this->setWindowTitle("Заказы база данных ");


    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); //загрузка основного изображения
    int widht= ui->mainpicture->width();    //получение размеровизображения
    int height=ui->mainpicture->height();
    ui->mainpicture->setPixmap(mainpix.scaled(widht, height));  //установка изображения


    table=new QSqlTableModel();
    table->setEditStrategy(QSqlTableModel::OnManualSubmit);
    table->setTable("book_base");
    table->select();

     ui->tableView->setModel(table);
     ui->tableView->resizeColumnsToContents();
     ui->tableView->show();
}

database_book::~database_book()
{
    delete ui;
}

void database_book::on_pushButton_clicked()
{
     table->revertAll();
}
