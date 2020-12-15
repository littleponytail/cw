#include "admin_authorization.h"
#include "ui_admin_authorization.h"
#include "admin_menu.h"
#include "QMessageBox"
admin_authorization::admin_authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_authorization)
{
    ui->setupUi(this);
    this->setWindowTitle("Окно авторизации ");
    this->setWindowFlags(Qt::WindowTitleHint);
    QPixmap mainpix("C:/Zarodysh/imaginary_mouse/pictures/unnamed (1).jpg"); //загрузка основного изображения
    int w= ui->mainpicture->width();    //получение размеровизображения
    int h=ui->mainpicture->height();
    ui->mainpicture->setPixmap(mainpix.scaled(w, h));  //установка изображения

}

admin_authorization::~admin_authorization()
{
    delete ui;
}

void admin_authorization::on_pushButton_clicked()
{
    QString qlogin=ui->aalogin->text();
    QString qpassword=ui->aapassword->text();
    int result;
    result=aaccountcheck(qlogin, qpassword);
   if(result==-2){QMessageBox::warning(this, "Ошибка соединения", "База данных не была открыта");return;}
  else if(result==-1){QMessageBox::warning(this, "Ошибка соединения", "База данных пуста ");return;}
   else if (result==1){QMessageBox::warning(this, "Ошибка ввода", "Неверный пароль");return;}
  else if (result==2){QMessageBox::warning(this, "Ошибка ввода", "Несуществующий логин"); return;}
   if(ui->aakey->text()!="П*ФИЛЬМЫ")return;
   hide();
   admin_menu window;
   window.exec();
   close();
}
