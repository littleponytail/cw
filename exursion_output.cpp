#include "exursion_output.h"
#include "ui_exursion_output.h"
#include "excursion.h"
#include "headers.h"
#include "book_window.h"
exursion_output::exursion_output(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exursion_output)
{
    ui->setupUi(this);
     this->setWindowTitle("Информация экскурсии ");
}
   exursion_output:: exursion_output(QString client_login, int id, QWidget *parent):
   QDialog(parent),
    ui(new Ui::exursion_output)
{
    this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowTitle("Информация экскурсии ");

    ui->setupUi(this);
     this->setWindowTitle("Информация экскурсии ");
    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); //загрузка основного изображения
    int w= ui->mainpicture->width();    //получение размеровизображения
    int h=ui->mainpicture->height();
    ui->mainpicture->setPixmap(mainpix.scaled(w, h));  //установка изображения

    QPixmap pix0("C:/Zarodysh/imaginary_mouse/pictures/user.png"); //загрузка основного изображения
    int widgth0= ui->user_icon->width();    //получение размеровизображения
    int height0=ui->user_icon->height();
    ui->user_icon->setPixmap(pix0.scaled(widgth0, height0));//установка изображения


    this->id=id;
    this->login=client_login;
    ui->login->setText(client_login);
    excursion excursion;
    excursion.set_info(id);
    ui->first_date->setText(part_output(excursion.get_arrival_date(),0,10));
    ui->second_date->setText(part_output(excursion.get_arrival_date(),12,22));
    ui->third_date->setText(part_output(excursion.get_arrival_date(),24,34));
    ui->fouth_date->setText(part_output(excursion.get_arrival_date(),36,46));
    ui->fifth_date->setText(part_output(excursion.get_arrival_date(),48,58));
    ui->sixth_date->setText(part_output(excursion.get_arrival_date(),60,70));
    ui->seventh_date->setText(part_output(excursion.get_arrival_date(),72,82));
    ui->eighth_date->setText(part_output(excursion.get_arrival_date(),84,94));
    ui->ninth_date->setText(part_output(excursion.get_arrival_date(),96,106));
    ui->tenth_date->setText(part_output(excursion.get_arrival_date(),108,118));
    ui->eleventh_date->setText(part_output(excursion.get_arrival_date(),120,130));
    ui->twelth_date->setText(part_output(excursion.get_arrival_date(),132,142));
     ui->thirteen_date ->setText(part_output(excursion.get_arrival_date(),144,154));
     ui->fourteenht_date->setText(part_output(excursion.get_arrival_date(),156,166));
     ui->fifteenth_date->setText(part_output(excursion.get_arrival_date(),168,178));
     ui->sixteenth_date->setText(part_output(excursion.get_arrival_date(),180,190));
     ui->seventeenth_date->setText(part_output(excursion.get_arrival_date(),202,212));
     ui->eighteenth_date->setText(part_output(excursion.get_arrival_date(),214,224));
     ui->nineteenth_date->setText(part_output(excursion.get_arrival_date(),236,246));
     ui->twenteenth_date->setText(part_output(excursion.get_arrival_date(),258,268));

   // ui->arrivel_dates->setText(excursion.get_arrival_date());
   // ui->arrivel_dates->setWordWrap(true);

    QPixmap pix(excursion.get_picture_path());
    int width= ui->picture->width();
    int height=ui->picture->height();
    ui->picture->setPixmap(pix.scaled(width,height));
    ui->name->setText(excursion.get_name());
    ui->description->setText(excursion.get_desription());
    ui->description->setWordWrap(true);
    ui->country_2->setText(excursion.get_country_name());
    ui->hotel_name->setText(excursion.get_hotel_name());
    char hotel_rate[6]="     ";
    for(int i=0; i<excursion.get_hotel_rate(); i++)hotel_rate[6-i]='*';
    ui->hotel_rate->setText(hotel_rate);
    ui->meals->setText(excursion.get_meals());
    ui->nights->setText(QString::number(excursion.get_nights_amount()));
    if(excursion.get_transport_type()==0) ui->transport->setText("Самолет ");
    if(excursion.get_transport_type()==1) ui->transport->setText("Поезд ");
    if(excursion.get_transport_type()==3) ui->transport->setText("Самолет & Лайнер ");
    if(excursion.get_transport_type()==4) ui->transport->setText("Самолет & Автобус");
    if(excursion.get_transport_type()==5) ui->transport->setText("Лайнер & Поезд ");
    if(excursion.get_transport_type()==6) ui->transport->setText("Лайнер & Автобус");
    ui->rate->setText(QString::number(excursion.get_rate()));

}

exursion_output::~exursion_output()
{
    delete ui;
}

int exursion_output::get_id(){return id;}

void exursion_output::on_first_date_clicked()
{
   book_window window( this->login,this->get_id(), part_output(ui->first_date->text(),0,10));
   window.setModal(true);
   window.exec();

}

void exursion_output::on_second_date_clicked()
{
    book_window window( this->login, this->get_id(),ui->second_date->text());
    window.setModal(true);
    window.exec();


}

void exursion_output::on_third_date_clicked()
{
    book_window window( this->login,this->get_id(),ui->third_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_fouth_date_clicked()
{
    book_window window( this->login,this->get_id(),ui->fouth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_fifth_date_clicked()
{
    if(ui->fifth_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->fifth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_sixth_date_clicked()
{
   book_window window( this->login, this->get_id(),ui->sixth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_seventh_date_clicked()
{
   book_window window( this->login, this->get_id(),ui->seventh_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_eighth_date_clicked()
{
    if(ui->eighth_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->eighth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_ninth_date_clicked()
{
    if(ui->ninth_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->ninth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_tenth_date_clicked()
{
    if(ui->tenth_date->text()==nullptr)return;
   book_window window( this->login, this->get_id(),ui->tenth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_eleventh_date_clicked()
{
    if(ui->eleventh_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->eleventh_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_twelth_date_clicked()
{
    if(ui->twelth_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->twelth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_thirteen_date_clicked()
{
    if(ui->thirteen_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->twelth_date->text());
    window.setModal(true);
    window.exec();


}

void exursion_output::on_fourteenht_date_clicked()
{
    if(ui->fourteenht_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->twelth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_fifteenth_date_clicked()
{
    if(ui->fifteenth_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->twelth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_sixteenth_date_clicked()
{
    if(ui->sixteenth_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->twelth_date->text());
    window.setModal(true);
    window.exec();


}

void exursion_output::on_seventeenth_date_clicked()
{
    if(ui->seventeenth_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->twelth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_eighteenth_date_clicked()
{
    if(ui->eighteenth_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->twelth_date->text());
    window.setModal(true);
    window.exec();

}

void exursion_output::on_nineteenth_date_clicked()
{
    if(ui->nineteenth_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->twelth_date->text());
    window.setModal(true);
    window.exec();


}

void exursion_output::on_twenteenth_date_clicked()
{
    if(ui->twenteenth_date->text()==nullptr)return;
    book_window window( this->login, this->get_id(),ui->twelth_date->text());
    window.setModal(true);
    window.exec();

}
