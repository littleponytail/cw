#include "admin_menu.h"
#include "ui_admin_menu.h"
#include"database_excursion.h"
#include "database_people_amount.h"
#include "excursion.h"
#include "database_book.h"
#include "administrator_check.h"
admin_menu::admin_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_menu)
{

     this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
     ui->setupUi(this);
     this->setWindowTitle("Окно меню ");
     QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); //загрузка основного изображения
     int w= ui->mainpicture->width();    //получение размеровизображения
     int h=ui->mainpicture->height();
     ui->mainpicture->setPixmap(mainpix.scaled(w, h));  //установка изображения
     QPixmap pix("C:/Zarodysh/imaginary_mouse/pictures/user.png"); //загрузка основного изображения


     excursion * excursions;
     excursions=new excursion[12];  //загрузка информации о первых 12 турах
     for (int i=0; i<12;i++)excursions[i].set_info(i+1);

     QPixmap pix1(excursions[0].get_picture_path()); //загрзука первого изображения
     int w1= ui->picture_1->width();                 //установка размеров изображений
     int h1=ui->picture_1->height();
     ui->picture_1->setPixmap(pix1.scaled(w1,h1));  //установка изображения
     ui->country_1->setText(excursions[0].get_country_name());      //запись страны первого тура
     ui->price_1->setText(QString::number(excursions[0].get_price())+" BYN"); // запись цены первого тура
     ui->name_1->setText(excursions[0].get_name());                           //запись названия первого тура
     ui->meals_1->setText(excursions[0].get_meals());  //запись типа питания в отеле первого тура
     ui->nights_1->setText(QString::number(excursions[0].get_nights_amount()));   //запись количества ночей первого тура

     QPixmap pix2(excursions[1].get_picture_path());  // аналогиные действия для второго труа
     ui->picture_2->setPixmap(pix2.scaled(w1,h1));
     ui->country_2->setText(excursions[1].get_country_name());
     ui->price_2->setText(QString::number(excursions[1].get_price())+" BYN");
     ui->name_2->setText(excursions[1].get_name());
     ui->meals_2->setText(excursions[1].get_meals());
     ui->nights_2->setText(QString::number(excursions[1].get_nights_amount()));


     QPixmap pix3(excursions[2].get_picture_path());
     ui->picture_3->setPixmap(pix3.scaled(w1,h1));
     ui->country_3->setText(excursions[2].get_country_name());
     ui->price_3->setText(QString::number(excursions[2].get_price())+" BYN");
     ui->name_3->setText(excursions[2].get_name());
     ui->meals_3->setText(excursions[2].get_meals());
     ui->nights_3->setText(QString::number(excursions[2].get_nights_amount()));


     QPixmap pix4(excursions[3].get_picture_path());
     ui->picture_4->setPixmap(pix4.scaled(w1,h1));
     ui->country_4->setText(excursions[3].get_country_name());
     ui->price_4->setText(QString::number(excursions[3].get_price())+" BYN");
     ui->name_4->setText(excursions[3].get_name());
     ui->meals_4->setText(excursions[3].get_meals());
     ui->nights_4->setText(QString::number(excursions[3].get_nights_amount()));


     QPixmap pix5(excursions[4].get_picture_path());
     ui->picture_5->setPixmap(pix5.scaled(w1,h1));
     ui->country_5->setText(excursions[4].get_country_name());
     ui->price_5->setText(QString::number(excursions[4].get_price())+" BYN");
     ui->name_5->setText(excursions[4].get_name());
     ui->meals_5->setText(excursions[4].get_meals());
     ui->nights_5->setText(QString::number(excursions[4].get_nights_amount()));


     QPixmap pix6(excursions[5].get_picture_path());  // аналогиные действия для второго труа
     ui->picture_6->setPixmap(pix6.scaled(w1,h1));
     ui->country_6->setText(excursions[5].get_country_name());
     ui->price_6->setText(QString::number(excursions[5].get_price())+" BYN");
     ui->name_6->setText(excursions[5].get_name());
     ui->meals_6->setText(excursions[5].get_meals());
     ui->nights_6->setText(QString::number(excursions[5].get_nights_amount()));


     QPixmap pix7(excursions[6].get_picture_path());
     ui->picture_7->setPixmap(pix7.scaled(w1,h1));
     ui->country_7->setText(excursions[6].get_country_name());
     ui->price_7->setText(QString::number(excursions[6].get_price())+" BYN");
     ui->name_7->setText(excursions[6].get_name());
     ui->meals_7->setText(excursions[6].get_meals());
     ui->nights_7->setText(QString::number(excursions[6].get_nights_amount()));


     QPixmap pix8(excursions[7].get_picture_path());
     ui->picture_8->setPixmap(pix8.scaled(w1,h1));
     ui->country_8->setText(excursions[7].get_country_name());
     ui->price_8->setText(QString::number(excursions[7].get_price())+" BYN");
    ui->name_8->setText(excursions[7].get_name());
     ui->meals_8->setText(excursions[7].get_meals());
     ui->nights_8->setText(QString::number(excursions[7].get_nights_amount()));


     QPixmap pix9(excursions[8].get_picture_path());
     ui->picture_9->setPixmap(pix9.scaled(w1,h1));
     ui->country_9->setText(excursions[8].get_country_name());
     ui->price_9->setText(QString::number(excursions[8].get_price())+" BYN");
     ui->name_9->setText(excursions[8].get_name());
     ui->meals_9->setText(excursions[8].get_meals());
     ui->nights_9->setText(QString::number(excursions[8].get_nights_amount()));


     QPixmap pix10(excursions[9].get_picture_path());
     ui->picture_10->setPixmap(pix10.scaled(w1,h1));
     ui->country_10->setText(excursions[9].get_country_name());
     ui->price_10->setText(QString::number(excursions[9].get_price())+" BYN");
     ui->name_10->setText(excursions[9].get_name());
     ui->meals_10->setText(excursions[9].get_meals());
     ui->nights_10->setText(QString::number(excursions[9].get_nights_amount()));

     QPixmap pix11(excursions[10].get_picture_path());
     ui->picture_11->setPixmap(pix11.scaled(w1,h1));
     ui->country_11->setText(excursions[10].get_country_name());
     ui->price_11->setText(QString::number(excursions[10].get_price())+" BYN");
     ui->name_11->setText(excursions[10].get_name());
     ui->meals_11->setText(excursions[10].get_meals());
     ui->nights_11->setText(QString::number(excursions[10].get_nights_amount()));

     QPixmap pix12(excursions[11].get_picture_path());
     ui->picture_12->setPixmap(pix12.scaled(w1,h1));
     ui->country_12->setText(excursions[11].get_country_name());
     ui->price_12->setText(QString::number(excursions[11].get_price())+" BYN");
     ui->name_12->setText(excursions[11].get_name());
     ui->meals_12->setText(excursions[11].get_meals());
     ui->nights_12->setText(QString::number(excursions[11].get_nights_amount()));



     delete[]excursions;
 }

admin_menu::~admin_menu()
{
    delete ui;
}

void admin_menu::on_pushButton_clicked()
{
    //Administrator_check window;
   // window.setModal(true);
    //window.exec();
    Database_excursion win;
    win.setModal(true);
    win.exec();
}

void admin_menu::on_pushButton_4_clicked()
{database_people_amount window;
    window.setModal(true);
    window.exec();

}

void admin_menu::on_pushButton_3_clicked()
{
        database_book window;
        window.setModal(true);
        window.exec();

}
