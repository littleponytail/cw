
#include "excursion.h"

excursion::excursion()
{ex_id=last_id();
    country="Country";
      name="Hot tour";
     hotel_rate=0;
      icon_path=":/new/R5Mqv1jLkHI.jpg";
      price=0.0;
      meals="room only";
      this->arrival_dates="00.00.0000";
      this->exursion_description="Sorry, information will be upadted latter";

};


excursion:: excursion( int hotel_rate,  int transport,  QString country,  QString meals, int nights_amount, float rate,QString hotel_name,
 QString name, QString arrival_dates)
{   this->hotel_rate=  hotel_rate;
    this->rate=rate;
    this->transport_type= transport;
    this->country= country;
    this->meals= meals;
    this->nights_amount=nights_amount;
    this->hotel_name= hotel_name;
    this->name= name;
    this->arrival_dates= arrival_dates;
};



excursion:: excursion(QString country, QString name, QString hotel_rate, QString picture_path, QString price, QString meals)
 {
       ex_id=last_id();
       this->country=country;
       this->name=name;
       this->hotel_rate=hotel_rate.toInt();
       this-> icon_path= picture_path;
       this->price=price.toFloat();
       this->meals=meals;
 };


int excursion :: set_info(int id){
    QSqlDatabase db1=QSqlDatabase::database();
 if (!db1.open())return -1;
        QSqlQuery query1= QSqlQuery(db1);
        if (!query1.exec("SELECT * FROM excursion_base_rus") ){db1.close();return 1; }
        while(query1.next())if(query1.value("ID")==id){
        this->ex_id=id;
        this->price= query1.value("PRICE").toFloat();
        this->name= query1.value("NAME").toString();
        this->rate=query1.value("RATE").toFloat();
        this->country= query1.value("COUNTRY").toString();
        this->hotel_rate= query1.value("HOTEL_RATE").toInt();
        this->transport_type= query1.value("TRANSPORT").toInt();
        this->nights_amount=query1.value("NIGHTS").toInt();
        this->arrival_dates= query1.value("BEGIN_DATE").toString();
        this->description= query1.value("DESCRIPRION").toString();
        this->meals= query1.value("MEALS").toString();
        this->icon_path= query1.value("ICON_PATH").toString();
        this->hotel_name= query1.value("HOTEL_NAME").toString();
        this->departure_time=query1.value("DEPARTURE_TIME").toString();
        this->departure_place=query1.value("DEPARTURE_PLACE").toString();
        this->arrivel_time=query1.value("ARRIVAL_TIME").toString();
        return 0;
 }
 db1.close();
 return 2;
};


int last_id(){
    int id;
    QSqlDatabase db1=QSqlDatabase::database();
    if (!db1.open())return -2;
    QSqlQuery query1= QSqlQuery(db1);
    if (!query1.exec("SELECT ID FROM exursion_base") ){db1.close();return -1; }
    while(query1.next()) id= query1.value("ID").toInt();
    return id;
}



QString * countrys_search(){
    QSqlDatabase db1=QSqlDatabase::database();
    QString * array;
    int size;
 if (!db1.open())throw "Database wasn't open";
 QSqlQuery query1= QSqlQuery(db1);
    if (!query1.exec("SELECT COUNTRY FROM exursion_base") )throw "Database is empty";
    while(query1.next()) {}

}
