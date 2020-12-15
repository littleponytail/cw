#include "imaginary_mouse_client.h"
#include "ui_imaginary_mouse_client.h"
#include "finded_exursinsions.h"
#include "exursion_output.h"
#include "excursion.h"
#include "QMessageBox"
#include "headers.h"
#include "client_cabinet.h"
#include "client.h"


Imaginary_mouse_client::Imaginary_mouse_client(QString client_login, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Imaginary_mouse_client)
{
    this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);

    this->setWindowTitle("Меню ");
    client cur;
    this->client_login=client_login;
    ui->login->setText( this->client_login);
    ui->Hotel_rate->setEditable(true);// добавлние возможности редактирования предложенных вариантов
    ui->Transport->setEditable(true);
    ui->Meals->setEditable(true);
    ui->Country->setEditable(true);
    ui->Transport->lineEdit()->setReadOnly(true);
    ui->Meals->lineEdit()->setReadOnly(true);


    ui->Hotel_rate->addItem(nullptr);// добавление нулевых вариантов
    ui->Transport->addItem(nullptr);
    ui->Meals->addItem(nullptr);
    ui->Country->addItem(nullptr);

    ui->Hotel_rate->addItem("★★★");// добавление имеющихся в базе данных вариантов рейтинга отлея
    ui->Hotel_rate->addItem("★★★★");
    ui->Hotel_rate->addItem("★★★★★");


    ui->Country->addItem("Турция");// добавление имеющихся в базе данных вариантов рейтинга отлея
    ui->Country->addItem("Египет");
    ui->Country->addItem("Италия");
    ui->Country->addItem("Черногория");



    ui->Transport->addItem("Самолет");// добавление имеющихся в базе данных вариантов транспорта
    ui->Transport->addItem("Поезд");
    ui->Transport->addItem("Автобус");
    ui->Transport->addItem("Самолет & Лайнер");
    ui->Transport->addItem("Самолет & Автобус");
    ui->Transport->addItem("Лайнер & Поезд");
    ui->Transport->addItem("Лайнер & Автобус");



    ui->Meals->addItem("Все включено ултьра");// добавление имеющихся в базе данных вариантов типа питания в отелях
    ui->Meals->addItem("Все включено");
    ui->Meals->addItem("Полный пансион");
    ui->Meals->addItem("Полупансион");
    ui->Meals->addItem("Кровать и завтрак");
    ui->Meals->addItem("Только комната");



    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); //загрузка основного изображения
    int w= ui->mainpicture->width();    //получение размеровизображения
    int h=ui->mainpicture->height();
    ui->mainpicture->setPixmap(mainpix.scaled(w, h));  //установка изображения
    QPixmap pix("C:/Zarodysh/imaginary_mouse/pictures/user.png"); //загрузка основного изображения
    int widgth= ui->user_icon->width();    //получение размеровизображения
    int height=ui->user_icon->height();
    ui->user_icon->setPixmap(pix.scaled(widgth, height));//установка изображения


    excursion * excursions;
    excursions=new excursion[12];  //загрузка информации о первых 12 турах
    for (int i=0; i<12;i++)excursions[i].set_info(i+1);

    QPixmap pix1(excursions[0].get_picture_path()); //загрзука первого изображения
    int w1= ui->picture_1->width(); //установка размеров изображений
    int h1=ui->picture_1->height();
    ui->picture_1->setPixmap(pix1.scaled(w1,h1));  //установка изображения
    ui->country_1->setText(excursions[0].get_country_name()); //запись страны первого тура
    ui->price_1->setText(QString::number(excursions[0].get_price())+" BYN"); // запись цены первого тура
    ui->name_1->setText(excursions[0].get_name());  //запись названия первого тура
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



Imaginary_mouse_client::~Imaginary_mouse_client()
{
    delete ui;
}

void Imaginary_mouse_client::search()
{
     QString hotel_rate=ui->Hotel_rate->lineEdit()->text();
     QString transport_name=ui->Transport->lineEdit()->text();
     QString country=ui->Country->lineEdit()->text();
     QString meals=ui->Meals->lineEdit()->text();
     QString nights=ui->Nights_amount->text();
     QString rate=ui->Rate->text();
     QString hotel_name=ui->Hotel_name->text();
     QString name=ui->Excursion_name->text();
     QString date=ui->Date->text();
     QString price_from=ui->Price_from->text();
     QString price_to=ui->Price_to->text();
     int transport_type;
     int int_hotel_rate;

    if (find_first_not_of( "★", hotel_rate)){QMessageBox::warning(this,"Ошибка ввода", "Введите существующий рейтинг, для ввода используйте '★'."); return;}
    int_hotel_rate=hotel_rate.length();
    if (int_hotel_rate>5){QMessageBox::warning(this,"Ошибка вводаt", "Слишком хороший отлеь.");return;}
    if(price_from.length()>price_to.length()||(price_from.length()==price_to.length() && price_from>price_to)){QMessageBox::warning(this,"Ошибка ввода", "Минимальная цена должна быть меньше максимальной.");return;}

    if (transport_name.compare("Самолет")==0)transport_type=0;
    else if(transport_name.compare("Поезд")==0)transport_type=1;
    else if(transport_name.compare("Автобус")==0)transport_type=2;
    else if(transport_name.compare("Самолет & Лайнер")==0)transport_type=3;
    else if(transport_name.compare("Самолет & Автобус")==0)transport_type=4;
    else if(transport_name.compare("Лайнер & Поезд")==0)transport_type=5;
    else if(transport_name.compare("Лайнер & Автобус")==0)transport_type=6;
    else if(transport_name==nullptr)transport_type=-1;


     excursion example(int_hotel_rate,transport_type, country, meals, nights.toInt(), rate.toFloat(), hotel_name, name, date);


        this->hide();
        Finded_exursinsions win(this->client_login,example, price_from, price_to);
        win.setModal(true);
        win.exec();
        show();
}

void Imaginary_mouse_client::on_pushButton_3_clicked()
{
    search();
}

void Imaginary_mouse_client::on_pushButton_11_clicked()
{
  exursion_output window(this->client_login,1);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_13_clicked()
{
    exursion_output window(this->client_login,1);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_14_clicked()
{
    exursion_output window(this->client_login,1);
    window.setModal(true);
    window.exec();
}

void Imaginary_mouse_client::on_pushButton_2_clicked()
{ exursion_output window(this->client_login,2);
    window.setModal(true);
    window.exec();

}

void Imaginary_mouse_client::on_pushButton_5_clicked()
{
    exursion_output window(this->client_login,3);
    window.setModal(true);
    window.exec();
}

void Imaginary_mouse_client::on_pushButton_12_clicked()
{
    exursion_output window(this->client_login,4);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_18_clicked()
{
  client_cabinet window(client_login);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_7_clicked()
{
    exursion_output window(this->client_login,5);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_4_clicked()
{
    exursion_output window(this->client_login,6);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_6_clicked()
{
    exursion_output window(this->client_login,7);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_23_clicked()
{
    exursion_output window(this->client_login,8);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_10_clicked()
{
    exursion_output window(this->client_login,9);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_8_clicked()
{
    exursion_output window(this->client_login,10);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_9_clicked()
{
    exursion_output window(this->client_login,11);
  window.setModal(true);
  window.exec();
}

void Imaginary_mouse_client::on_pushButton_27_clicked()
{
    exursion_output window(this->client_login,12);
  window.setModal(true);
  window.exec();
}
