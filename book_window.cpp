#include "book_window.h"
#include "ui_book_window.h"
#include "information.h"
#include "QMessageBox"
#include "excursion.h"


book_window::book_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_window)
{
    ui->setupUi(this);

}
book_window::book_window(QString login,int id,QString date, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_window)
{

    this->setWindowFlags(Qt::WindowTitleHint);



    client cur_client(login);
    cur_client.get_information(login);
    this->cur_client=cur_client;
    ui->setupUi(this);

    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); //загрузка основного изображения
    int w= ui->mainpicture->width();    //получение размеровизображения
    int h=ui->mainpicture->height();
    ui->mainpicture->setPixmap(mainpix.scaled(w, h));  //установка изображения

     this->setWindowTitle("Окно брони ");
    ui->date->setText(date);
    excursion exc;
    exc.set_info(id);
    this->id=id;
    ui->name->setText(cur_client.get_name()+" "+cur_client.get_surname());
    ui->departure_time->setText(exc.get_deparure_time());
     ui->departure_place->setText(exc.get_deparure_place());
      ui->arrivel_time->setText(exc.get_arrivel_time());
    search_date[0]=date[0];
    search_date[1]=date[1];
    search_date[2]='/';
    search_date[3]=date[3];
    search_date[4]=date[4];
}
book_window::~book_window()
{
    delete ui;
}


void book_window::on_pushButton_2_clicked()
{
    this->close();
}

void book_window::on_pushButton_clicked()
{
    book();

}
void book_window:: book (){int amount;
 int people_amount=ui->adults->text().toInt();
 people_amount+=ui->children->text().toInt();
 QSqlDatabase db=QSqlDatabase::database();
 QSqlQuery query= QSqlQuery(db);
 if (!query.exec("SELECT * FROM people_amount2") ){db.close();return;}
 while(query.next())if(query.value("ID").toInt()==id) if(query.value(search_date).toInt()<people_amount){
 QMessageBox::warning(this, "Ошибка ввода", "Извините, слишком много человек, число оставшихся мест: "+query.value(search_date).toString());
 return;}
 else {amount=query.value(search_date).toInt()-people_amount;
 query.prepare("UPDATE `people_amount2` SET `"+search_date+"`="+QString::number(amount)+" WHERE ID="+QString::number(id));
 if(!query.exec())QMessageBox::warning(this, "Ошибка", "Не удалось связаться с базой данных, извините за неудобства, попытайтесь позже");
                         }
 query.prepare("INSERT INTO  book_base (USER_ID, EXCURSION_ID, DATE, PEOPLE_AMOUNT)" "VALUES (:USER_ID, :EXCURSION_ID, :DATE, :PEOPLE_AMOUNT )");
 query.addBindValue(cur_client.simple_get_id());
 query.addBindValue(id);
 query.addBindValue(search_date );
 query.addBindValue(people_amount);
 if(!query.exec())QMessageBox::warning(this, "Ошибка", "");
 information win;
 win.setModal(true);
  win.exec();
  this->close();

}
