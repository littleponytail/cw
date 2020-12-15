#include "finded_exursinsions.h"
#include "ui_finded_exursinsions.h"
#include "exursion_show.h"
#include "QListWidgetItem"
#include "QDebug"
#include "excursion.h"
#include "imaginary_mouse_client.h"
int find_ex(excursion example, QString price_from, QString price_to, int last_finded);
Finded_exursinsions::Finded_exursinsions(QString cur_login,excursion example, QString price_from, QString price_to, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Finded_exursinsions)
{     this->setWindowFlags(Qt::WindowTitleHint);
       bool first_excursion=false, second_excursion=false;
       ui->setupUi(this);
       this->setWindowTitle("Поиск ");
       this->cur_login=cur_login;
       int amount=0;
       int cur_id=-1;
       while (true){
       cur_id=find_ex(example, price_from, price_to, cur_id);
       if(cur_id==-1)break;
       if(cur_id==1)first_excursion=true;
       if(cur_id==2)second_excursion=true;
       QListWidgetItem * item=new QListWidgetItem;
       excursion * new_excursion= new excursion;
       new_excursion->set_info(cur_id);
       exursion_show * newelement;
       newelement = new exursion_show(this->cur_login,new_excursion);
       ui->listWidget->addItem(item);
       item->setSizeHint(QSize(0, 200));
       ui->listWidget->setItemWidget(item, newelement);
       amount++;
   }
        if (amount==0){ui->recomended_1->setText("Извините, экскурсии не найдены. Предлагаемые эксурсии ");}
        else if (amount==1){ui->recomended_2->setText("Предлагаемые эксурсии: ");}
        else if (amount==2){ui->recomended_3->setText("Предлагаемые эксурсии: ");}
        for (int id=1; amount<3; amount++){
        QListWidgetItem * item=new QListWidgetItem;
        excursion * new_excursion= new excursion;
        if(first_excursion && id==1){id++;}
        if(second_excursion && id==2){id++;}
        new_excursion->set_info(id);
        exursion_show * newelement;
        newelement = new exursion_show(this->cur_login, new_excursion);
        ui->listWidget->addItem(item);
        item->setSizeHint(QSize(0, 200));
        ui->listWidget->setItemWidget(item, newelement);
        id++;
    }
}
Finded_exursinsions::~Finded_exursinsions()
{
    delete ui;
}
int find_ex(excursion example, QString price_from, QString price_to, int last_finded){
    QSqlDatabase db1=QSqlDatabase::database();
    if (!db1.open())return -1;
    QSqlQuery query1= QSqlQuery(db1);
    if (!query1.exec("SELECT * FROM excursion_base_rus") ){db1.close();return 1; }
    while(query1.next()){int id=query1.value("ID").toInt();
    if (last_finded>=id)continue;
    if(example.get_name()!=nullptr && !query1.value("NAME").toString().contains(example.get_name())) continue;
    if(example.get_hotel_name()!=nullptr && find_first_not_of(example.get_hotel_name()," ") && !query1.value("HOTEL_NAME").toString().contains(example.get_hotel_name())) continue;
    if(price_to.toFloat()!=0 && (query1.value("PRISE").toFloat()>price_to.toFloat() || query1.value("PRIСE").toFloat()<price_from.toFloat())) continue;
    if(!query1.value("BEGIN_DATE").toString().contains(example.get_arrival_date()))continue;
    if(example.get_country_name()!=nullptr && !query1.value("COUNTRY").toString().contains(example.get_country_name()))continue;
    if(example.get_hotel_rate()!=0 && example.get_hotel_rate()!=query1.value("HOTEL_RATE").toInt())continue;
    if(example.get_transport_type()!=-1 && example.get_transport_type()!=query1.value("TRANSPORT").toInt())continue;
    if(example.get_nights_amount()!=0 && example.get_nights_amount()!=query1.value("NIGHTS").toInt())continue;
    if(example.get_meals()!=nullptr && example.get_meals()!=query1.value("MEALS").toString()) continue;
    return id;
 }
    return -1;
}
void Finded_exursinsions::on_pushButton_clicked()
{   Imaginary_mouse_client win(this->cur_login);
    this->close();
  win.setModal(true);
    win.exec();

}
