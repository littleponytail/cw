#include "exursion_show.h"
#include "ui_exursion_show.h"
#include "excursion.h"
#include "exursion_output.h"
exursion_show:: exursion_show(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exursion_show)
{
    ui->setupUi(this);
    escountry="Country";
      esname="Hot tour";
      eshotel_rate="*";
      espicture_path=":/new/R5Mqv1jLkHI.jpg";
      esprice=0.0;
      esmeals="room only";
      ui->setupUi(this);
      QPixmap pix(this->getpicture_path());
      int w= ui->picture->width();
      int h=ui->picture->height();
      ui->picture->setPixmap(pix.scaled(w, h));
      ui->country->setText(this->getcountry_name());
      ui->price->setText(QString::number(this->getprice())+" BYN");
      ui->hotel->setText(this->gethotel_rate());
      ui->name->setText(this->getname());
      ui->meals->setText(this->getmeals());
      QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg");
      int w1= ui->background->width();
      int h1=ui->background->height();
      ui->background->setPixmap(mainpix.scaled(w1, h1));

}
exursion_show:: exursion_show(QString escountry, QString esname, QString eshotel_rate, QString espicture_path, QString esprice, QString esmeals, QWidget *parent):
     QWidget(parent),  ui(new Ui::exursion_show) {
    ui->setupUi(this);
       this->escountry=escountry;
        this->esname=esname;
        this->eshotel_rate=eshotel_rate;
        this-> espicture_path= espicture_path;
        this->esprice=esprice.toFloat();
        this->esmeals=esmeals;
    QPixmap pix(this->getpicture_path());
    int w= ui->picture->width();
    int h=ui->picture->height();
    ui->picture->setPixmap(pix.scaled(w, h));
    ui->country->setText(this->getcountry_name());
      ui->price->setText(QString::number(this->getprice())+" BYN");
      ui->hotel->setText(this->gethotel_rate());
      ui->name->setText(this->getname());
      ui->meals->setText(this->getmeals());
      QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg");
      int w1= ui->background->width();
      int h1=ui->background->height();
      ui->background->setPixmap(mainpix.scaled(w1, h1));

    }
exursion_show:: exursion_show(QString log,excursion* showed_exursion, QWidget * parent): QWidget(parent),  ui(new Ui::exursion_show) {

     this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    QPixmap pix(showed_exursion->get_picture_path());
    char hotel_rate[6]="     ";
    id=showed_exursion->get_id();
    this->log=log;
    int w= ui->picture->width();
    int h=ui->picture->height();
    ui->picture->setPixmap(pix.scaled(w, h));
    ui->country->setText(showed_exursion->get_country_name());
    ui->price->setText(QString::number(showed_exursion->get_price())+" BYN");
    for(int i=0; i<showed_exursion->get_hotel_rate(); i++)hotel_rate[6-i]='*';
    ui->hotel->setText(hotel_rate);
    ui->name->setText(showed_exursion->get_name());
    ui->meals->setText(showed_exursion->get_meals());
    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg");
    int w1= ui->background->width();
    int h1=ui->background->height();
    ui->background->setPixmap(mainpix.scaled(w1, h1));
    ui->meals->setText(showed_exursion->get_meals());
    //ui->->setText(showed_exursion->get_meals());
}
exursion_show::~exursion_show()
{
    delete ui;
}

void exursion_show::on_pushButton_2_clicked(){
exursion_output win(  this->log,this->get_id());
    win.setModal(true);
    win.exec();
}

void exursion_show::on_pushButton_3_clicked()
{
    exursion_output win(  this->log,this->get_id());
    win.setModal(true);
    win.exec();
}
