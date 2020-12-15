#include "change_info.h"
#include "ui_change_info.h"
#include "QMessageBox"
change_info::change_info(client cur_client, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change_info)
{
     this->setWindowFlags(Qt::WindowTitleHint);
    ui->setupUi(this);
     this->setWindowTitle("Исправление ");
    this->cur_client=cur_client;

    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); //загрузка основного изображения
    int widht= ui->mainpicture->width();    //получение размеровизображения
    int height=ui->mainpicture->height();
    ui->mainpicture->setPixmap(mainpix.scaled(widht, height));  //установка изображения

    QPixmap pix("C:/Zarodysh/imaginary_mouse/pictures/user.png"); //загрузка основного изображения
    int w= ui->user_icon->width();    //получение размеров изображения
    int h=ui->user_icon->height();
    ui->user_icon->setPixmap(pix.scaled(w, h));//установка изображения
    ui->rlogin->setText(cur_client.get_login());
    ui->rname->setText(cur_client.get_name());
    ui->rsurname->setText(cur_client.get_surname());
    ui->rbirthday->setText(cur_client.get_birthday());
    ui->rmail->setText(cur_client.get_email_adress());
    ui->rnumber->setText(cur_client.get_number());
    ui->rpassword->setText(cur_client.get_password());
    ui->lat_name->setText(cur_client.get_lat_name());
    ui->lat_surname->setText(cur_client.get_lat_surname());
    ui->paspoprt_term->setText(cur_client.get_pasport_date());
    ui->pasport_num->setText(QString::number(cur_client.get_pasport_num()));
    ui->pasport_seria->setText(cur_client.get_pasport_seria());
    ui->rbirthday->setText(cur_client.get_birthday());
}

change_info::~change_info()
{
    delete ui;
}

void change_info::on_pushButton_clicked()
{
   change_client_info();
}
void  change_info:: change_client_info(){
    QString qname=ui->rname->text();
   // if (!consicst_of_rus_letters_only(qname)){QMessageBox::critical(this, "Ошибка ввода", "Графа имени должна содрежать только русские  буквы "); return;}
   // if (qname.length()<2) {QMessageBox::warning(this, "Ошибка ввода", "Графа имени должна быть заполнена ");return;}
    QString qsurname=ui->rsurname->text();

  //  if (qsurname.length()<2)  {QMessageBox::warning(this, "Ошибка ввода", "Графа фамилии должна быть заполнена. "); return;}
   // if (!consicst_of_rus_letters_only(qsurname)){ QMessageBox::warning(this, "Ошибка ввода", "Графа фамилии должна содрежать только русские буквы "); return;}

    QString qlogin=ui->rlogin->text();
  //  int check=qlogincheck(qlogin);
  //  if(cur_client.get_login()!=qlogin && check==-1){QMessageBox::warning(this, "Ошибка соединения", "Отсутствует доступ к базе данных ");return;}
  //  else if(cur_client.get_login()!=qlogin && check==0){QMessageBox::warning(this, "Ошибка ввода", "Такой логин уже существует");return;}

    QString qspassword=ui->rpassword->text();//
  //  if(!Password_check(qspassword)){QMessageBox::warning(this, "Ошибка ввода", "Низкий уровень сложности. Пароль должен содрежать буквы и цифры. Длина пароля не менее 5 символов."); ui->rpassword->setText("");return;}



    QString qbirthday=ui->rbirthday->text();
    QString qnumber=ui->rnumber->text();
 //   if (find_first_not_of("0123456789", qnumber)){
  //  QMessageBox::warning(this, "Wrong input", "Phone number must contain numbers ");}
 //   QString qemail=ui->rmail->text();





   QString latin_name=ui->lat_name->text();
//   if (!consicst_of_letters_only(latin_name)){
//    QMessageBox::critical(this, "Ошибка ввода", "Графа должна содрежать только латинские буквы "); return;}


   QString latin_surname=ui->lat_surname->text();
//     if (!consicst_of_letters_only(latin_name)){
//     QMessageBox::critical(this, "Ошибка ввода", "Графа должна содрежать только латинские буквы "); return;}


   QString pasp_seria=ui->pasport_seria->text();
   QString pasp_date=ui->paspoprt_term->text();
   int pasp_num=ui->pasport_num->text().toInt();
   QString qemail=ui->rmail->text();


   int client_id=cur_client.simple_get_id();
  if(!cur_client.update(client_id, qname, qsurname, qnumber, qemail, qbirthday, latin_name, latin_surname, pasp_seria, pasp_date, pasp_num,qlogin, qspassword)){

          QMessageBox::warning(this, "Ошибка подключения", "Не удалось подключиться к базе данных, попытайтесьпозже ");}
}
