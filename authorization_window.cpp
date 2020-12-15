#include "authorization_window.h"
#include "ui_authorization_window.h"
#include "registration_window.h"
#include "imaginary_mouse_client.h"
#include<main_function.h>
#include "QMessageBox"
#include "admin_authorization.h"
#include "headers.h"
#include "client.h"
#include "user.h"

authorization_window::authorization_window(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::authorization_window)
{
     ui->setupUi(this);
     this->setWindowTitle("Окно авторизации ");
     Registrationwindow=new registration_window;
     connect(Registrationwindow, &registration_window::cansel, this, &authorization_window::show); //подключение сигналов окна регистрации
     connect(Registrationwindow, &registration_window::ok, this, &authorization_window::show);
     QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); // загрузка изображения
     int w= ui->mainpicture->width();
     int h=ui->mainpicture->height();
     ui->mainpicture->setPixmap(mainpix.scaled(w, h));


}

authorization_window::~authorization_window()
{
    delete ui;
}

void authorization_window::on_pushButton_2_clicked()
{
 Registrationwindow->show();
 this->close();
}


void authorization_window::on_pushButton_clicked()
{
}

void authorization_window::on_pushButton_3_clicked()
{
   hide();
   admin_authorization window1;
   window1.setModal(true);
   window1.exec() ;
  //show();
}



void authorization_window::on_authorization_clicked()
{

    QString qlogin=ui->alogin->text();
    QString qpassword=ui->apassword->text();
    int result;
    result=accountcheck(qlogin, qpassword);
   if(result==-2){QMessageBox::warning(this, "Ошибка соединения", "Не удалось подключиться к базе данных, попытайтесь позже");return;}
   else if(result==-1){QMessageBox::warning(this, "Ошибка соединения", "База данных пуста");return;}
  else if (result==1){QMessageBox::warning(this, "Ошибка ввода", "Неверный пароль ");return;}
  else if (result==2){QMessageBox::warning(this, "Ошибка ввода", "Несуществующий логин "); return;}
   hide();
   Imaginary_mouse_client window(qlogin);
   window.setModal(true);
   window.exec() ;

}
