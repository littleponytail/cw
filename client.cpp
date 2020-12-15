#include "client.h"


client::client():user(){number_of_tours=0;};
client::client(QString login,QString password):user(password, login) {number_of_tours=0;};
client::client(QString login):user(login){};
client::client(QString login,QString password, QString name, QString surname,QString birthday, QString number, QString mail,
QString lat_name, QString lat_surname,QString pasport_seria, QString pasport_date,int pasport_num,int number_of_tours){
this->login=login;
this->password=password;
this->name=name;
this->surname=surname;
this->birthday=birthday;
this->number=number;
this->email_arddress=mail;
this->lat_name=lat_name;
this->lat_surname=lat_surname;
this->pasport_date=pasport_date;
this-> pasport_seria=pasport_seria;
this->pasport_num=pasport_num;
this->number_of_tours=number_of_tours;
};
bool client:: get_information(QString login){
    QSqlDatabase db=QSqlDatabase::database();
    if (!db.open())return false;
    QSqlQuery query= QSqlQuery(db);
    if (!query.exec("SELECT * FROM clients_base") ){db.close();return false; }
    while(query.next())if(query.value("LOGIN")==login){
    this->id=query.value("ID").toInt();
    this->password=query.value("PASSWORD").toString();
    this->name= query.value("NAME").toString();
    this->surname= query.value("SURNAME").toString();
    this->birthday=query.value("BIRTHDAY").toString();
    this->number= query.value("NUMBER").toString();
    this->email_arddress= query.value("MAIL").toString();
    this->otzuv= query.value("COMMENTC_ABILITY").toBool();
    this->lat_name=query.value("LATIN_NAME").toString();
    this->lat_surname=query.value("LATIN_SURNAME").toString();
    this->pasport_date=query.value("PASPORT_TERM").toString();
    this-> pasport_seria=query.value("PASPORT_SERIA").toString();
    this->pasport_num=query.value("PASPORT_NUMBER").toInt();
    this->number_of_tours=query.value("TOUR_AMOUNT").toInt();
    return true;
}
      return false;
}
bool client:: put_information(){
    QSqlDatabase db=QSqlDatabase::database();
    if (!db.open())return false;
    QSqlQuery query= QSqlQuery(db);
    query.prepare("INSERT INTO clients_base (LOGIN, PASSWORD, NAME, SURNAME, BIRTHDAY, NUMBER, MAIL, COMMENT_ABILITY,LATIN_NAME, LATIN_SURNAME,PASPORT_SERIA, PASPORT_NUMBER, PASPORT_TERM)"
    "VALUES( :LOGIN, :PASSWORD, :NAME, :SURNAME, :BIRTHDAY, :NUMBER, :MAIL, :COMMENT_ABILITY, :LATIN_NAME, :LATIN_SURNAME, :PASPORT_SERIA, :PASPORT_NUMBER, :PASPORT_TERM)");
    query.addBindValue(login);
    query.addBindValue(password);
    query.addBindValue(name);
    query.addBindValue(surname);
    query.addBindValue(birthday);
    query.addBindValue(number);
    query.addBindValue(email_arddress);
    query.addBindValue(false);
    query.addBindValue(lat_name);
    query.addBindValue(lat_surname);
    query.addBindValue(pasport_seria);
    query.addBindValue(pasport_num);
    query.addBindValue(pasport_date);
    if(!query.exec())return false;
    return true;};
    int client:: get_client_id(QString login){QSqlDatabase db=QSqlDatabase::database();
                                   if (!db.open())return false;
                                   QSqlQuery query= QSqlQuery(db);
                                   if (!query.exec("SELECT * FROM clients_base") ){db.close();return false; }
                                   while(query.next())if(query.value("LOGIN")==login)break;
                                   return query.value("ID").toInt();
}


bool client:: update(int id,QString name,QString surname, QString number, QString email_ardress, QString birthday,QString lat_name,QString lat_surname,QString pasport_seria,QString pasport_date, int pasport_num, QString login, QString password)
{
    this->name=name;
    this->surname=surname;
    this->birthday=birthday;
    this->number=number;
    this->email_arddress=email_ardress;
    this->birthday=birthday;
    this->lat_name=lat_name;
    this->lat_surname=lat_surname;
    this->pasport_seria=pasport_seria;
    this->pasport_date=pasport_date;
    this->pasport_num=pasport_num;
    this->password=password;
    this->login=login;
    QSqlDatabase db=QSqlDatabase::database();
    if (!db.open())return false;
    QSqlQuery query= QSqlQuery(db);
    query.prepare("UPDATE `clients_base` SET `LOGIN` = '"+login+"', `PASSWORD` = '"+password+ "', `NAME` = '"+name+"', `SURNAME`= '"+surname+
    "', `BIRTHDAY` = '"+ birthday +"', `NUMBER` = '" + number+ "', `MAIL`= '" + email_ardress + "',`LATIN_NAME`= '" + lat_name+"', `LATIN_SURNAME` ='"+lat_surname+
    + "', `PASPORT_SERIA` = '"+pasport_seria+ "', `PASPORT_NUMBER` = "+QString::number(pasport_num)+ ", `PASPORT_TERM`= '"+pasport_date+"' WHERE ID = "+QString::number(id));
    if(!query.exec())return false;
    else return true;
}
