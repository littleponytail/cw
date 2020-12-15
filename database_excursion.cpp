#include "database_excursion.h"
#include "ui_database_excursion.h"
#include "QMessageBox"
#include "question.h"


Database_excursion::Database_excursion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Database_excursion)
{
      this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    this->setWindowTitle("Экскурсии база данных ");



    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); //загрузка основного изображения
    int widht= ui->mainpicture->width();    //получение размеровизображения
    int height=ui->mainpicture->height();
    ui->mainpicture->setPixmap(mainpix.scaled(widht, height));  //установка изображения


    table=new QSqlTableModel();
    table->setEditStrategy(QSqlTableModel::OnManualSubmit);
    table->setTable("excursion_base_rus");
    table->select();

                ui->tableView->setModel(table);
                ui->tableView->resizeColumnsToContents();
                ui->tableView->show();
}

Database_excursion::~Database_excursion()
{
    delete ui;
}
void Database_excursion:: add_row (){
     table->insertRow(table->rowCount());
};
void Database_excursion:: delete_row(){ int selected_row=ui->tableView->currentIndex().row();
                                        if (selected_row>=0)table->removeRow(selected_row);
                                        else  QMessageBox::warning(this, "Wrong input", "Строка не была выбрана");};
 void Database_excursion:: save_changes(){
     table->submitAll();
     question win;
     win.setModal(true);
     win.exec();};
void Database_excursion::on_pushButton_clicked()
{
  add_row();

}

void Database_excursion::on_pushButton_2_clicked()
{
   save_changes();
}

void Database_excursion::on_pushButton_3_clicked()
{
delete_row();

}

void Database_excursion::on_pushButton_4_clicked()
{
    table->revertAll();
}
