#include "registration_window.h"
#include "ui_registration_window.h"
#include "authorization_window.h"
#include <QMessageBox>
#include "client.h"
#include "headers.h"

registration_window::registration_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration_window)
{
    ui->setupUi(this);
    this->setWindowTitle("Окно регистрации ");
    this->setWindowFlags(Qt::WindowTitleHint);
    ui->rpassword->setEchoMode(QLineEdit::Password);
    ui->rpassword_check->setEchoMode(QLineEdit::Password);
    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); // загрузка изображения
    int w= ui->mainpicture->width();
    int h=ui->mainpicture->height();
    ui->mainpicture->setPixmap(mainpix.scaled(w, h));

}

registration_window::~registration_window()
{
    delete ui;
}

void registration_window::on_pushButton_2_clicked()
{ ui->rlogin->setText(nullptr);
  ui->rname->setText(nullptr);
  ui->rsurname->setText(nullptr);
  ui->rbirthday->setText(nullptr);
  ui->rmail->setText(nullptr);
  ui->rnumber->setText(nullptr);
  ui->rpassword_check->setText(nullptr);
  ui->rpassword->setText(nullptr);

   this->close();
   emit cansel();


}

void registration_window::on_pushButton_clicked()
{
    QString qname=ui->rname->text();
    if (!consicst_of_rus_letters_only(qname)){
       QMessageBox::warning(this, "Ошибка ввода", "Графа имени должна содержать только русские буквы. "); return;}
   if (qname.length()<2) {QMessageBox::warning(this, "Ошибка ввода", "Графа имени должна быть заполнена. ");return;}
   QString qsurname=ui->rsurname->text();
     if (qsurname.length()<2)  {QMessageBox::warning(this, "Ошибка ввода", "Графа фамилии должна быть заполнена. "); return;}
   if (!consicst_of_rus_letters_only(qsurname)){ QMessageBox::warning(this, "Ошибка ввода", "Графа фамилии должна содержать только русские буквы. "); return;}

      QString qlogin=ui->rlogin->text();
     int check=qlogincheck(qlogin);
  if(check==-1){QMessageBox::warning(this, "Ошибка подключения", "База данных не была открыта");return;}
   else if(check==0){QMessageBox::warning(this, "Ошибка воода", "Данный логин уже существует");return;}


      QString qspassword=ui->rpassword->text();//
      if(!Password_check(qspassword)){QMessageBox::warning(this, "Ошибка ввода", "Низкий уровень сложности. Пароль должен содрежать буквы и цифры. Длина пароля не менее 5 символов."); ui->rpassword->setText("");return;}
      QString qpassword_copy=ui->rpassword_check->text();
     if(QString::compare(qspassword,qpassword_copy))
        { QMessageBox::warning(this,"Ошибка ввода", "Пароли не совпадают, попробуйте еще раз "); ui->rpassword_check->setText(nullptr); ui->rpassword->setText(nullptr);}

       QString qbirthday=ui->rbirthday->text();
         QString qnumber=ui->rnumber->text();
         if (find_first_not_of("0123456789", qnumber)){
         QMessageBox::warning(this, "Ошибка ввода", "Номер телефона должен содержать толькоцифры. Вместо зачка + используйте общий код номера ");}
         QString qemail=ui->rmail->text();

         QString latin_name=ui->lat_name->text();
      //   if (!consicst_of_letters_only(latin_name)){
     //    QMessageBox::critical(this, "Ошибка ввода", "Графа должна содрежать только латинские буквы "); return;}


         QString latin_surname=ui->lat_surname->text();
    //     if (!consicst_of_letters_only(latin_name)){
    //     QMessageBox::critical(this, "Ошибка ввода", "Графа должна содрежать только латинские буквы "); return;}


         QString pasp_seria=ui->pasport_seria->text();
         QString pasp_date=ui->pasport_term->text();
         int pasp_num=ui->pasport_num->text().toInt();
         client *newclient;
         newclient=new client(qlogin, qspassword, qname, qsurname, qbirthday, qnumber, qemail, latin_name, latin_surname, pasp_seria, pasp_date, pasp_num,  0);
         if( (*newclient).put_information());
         else QMessageBox::warning(this, "Ошибка ввода", "База данных не была открыта");
         this->close();
         emit ok ();
};


void registration_window::on_pushButton_3_clicked()
{  static bool mode;
  if(!mode) { ui->rpassword->setEchoMode(QLineEdit::Normal);mode=true; return;}
  if(mode) { ui->rpassword->setEchoMode(QLineEdit::Password);mode=false; return;}

}

void registration_window::on_pushButton_4_clicked()
{ static bool mode;
    if(!mode) { ui->rpassword_check->setEchoMode(QLineEdit::Normal);mode=true; return;}
    if(mode) { ui->rpassword_check->setEchoMode(QLineEdit::Password);mode=false; return;}

}
