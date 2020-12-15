#include "client_cabinet.h"
#include "ui_client_cabinet.h"
#include "change_info.h"
#include"QPixmap"
client_cabinet::client_cabinet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_cabinet)
{
    ui->setupUi(this);
}
client_cabinet::client_cabinet(QString login, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client_cabinet)
{
     this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
     ui->setupUi(this);
     this->setWindowTitle("Личный кабинет ");

    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); //загрузка основного изображения
    int widht= ui->mainpicture->width();    //получение размеровизображения
    int height=ui->mainpicture->height();
    ui->mainpicture->setPixmap(mainpix.scaled(widht, height));  //установка изображения

    client cur_client(login);
    cur_client.get_information(login);
    this->cur_client= cur_client;
    QPixmap pix("C:/Zarodysh/imaginary_mouse/pictures/user.png"); //загрузка основного изображения
    int w= ui->icon->width();    //получение размеровизображения
    int h=ui->icon->height();
    ui->icon->setPixmap(pix.scaled(w, h));//установка изображения
    ui->name->setText(cur_client.get_name());
    ui->surname->setText(cur_client.get_surname());
    ui->mail->setText(cur_client.get_email_adress());
    ui->date->setText(cur_client.get_birthday());
    ui->number->setText(cur_client.get_number());
    ui->password->setText(cur_client.get_password());
    ui->login->setText(login);
    ui->name_lat->setText(cur_client.get_lat_name());
    ui->surname_lat->setText(cur_client.get_lat_surname());
    ui->pasport_date->setText(cur_client.get_pasport_date());
    ui->pasport_seria->setText(cur_client.get_pasport_seria());
    ui->pasport_number->setText(QString::number(cur_client.get_pasport_num()));

}
client_cabinet::~client_cabinet()
{
    delete ui;
}

void client_cabinet::on_pushButton_clicked()
{ change_info window(cur_client);
    window.setModal(true);
    window.exec();

}
