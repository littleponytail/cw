#include "database_people_amount.h"
#include "ui_database_people_amount.h"


database_people_amount::database_people_amount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::database_people_amount)
{
       this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    this->setWindowTitle("Количество мест база данных ");


    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); //загрузка основного изображения
    int widht= ui->mainpicture->width();    //получение размеровизображения
    int height=ui->mainpicture->height();
    ui->mainpicture->setPixmap(mainpix.scaled(widht, height));  //установка изображения


    table1=new QSqlTableModel();
    table1->setEditStrategy(QSqlTableModel::OnManualSubmit);
    table1->setTable("people_amount2");
    table1->select();
    ui->tableView->setModel(table1);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->show();
}
void database_people_amount:: autofill(){
    QSqlDatabase db1=QSqlDatabase::database();
    if (!db1.open()) return;
    QSqlQuery query1= QSqlQuery(db1);
     QSqlQuery query2=QSqlQuery(db1);
     if (!query1.exec("SELECT ID FROM exursion_base") ){return; }
     if (!query2.exec("SELECT ID FROM people_amount2") ){return; }
     while(query2.next())if(query2.value("ID")==query1.value("ID")){query1.next();
     }

}
database_people_amount::~database_people_amount()
{
    delete ui;
}


void database_people_amount::on_pushButton_clicked()
{
      table1->insertRow(table1->rowCount());
}

void database_people_amount::on_pushButton_3_clicked()
{
     table1->submitAll();
}
