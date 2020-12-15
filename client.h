#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include "headers.h"
#include "user.h"
class client: public user{
private:
    QString name;
    QString surname;
    QString number;
    QString email_arddress;
    QString birthday;
    QString lat_name;
    QString lat_surname;
    QString pasport_seria;
    QString pasport_date;
    int pasport_num;
    int number_of_tours;
    void registration() { };
    bool otzuv;

public:
   client();
   client(QString login,QString password);
   client(QString login);
   client(QString login,QString password, QString name, QString surname,QString birthday, QString number, QString mail,
   QString lat_name, QString lat_surname,QString pasport_seria, QString pasport_date,int pasport_num,int number_of_tours);
   bool put_information();
   bool get_information(QString login);
   bool get_information2(int id);
   QString get_name(){return name;}
   QString get_surname(){return surname;}
   QString get_number(){return number;}
   QString get_email_adress(){return email_arddress;}
   QString get_birthday(){return birthday;}
   int get_client_id(QString login);
   QString get_login(){return login;}
   int simple_get_id(){return id;}
   QString get_lat_name(){return lat_name;};
   QString get_lat_surname(){return lat_surname;};
   QString get_pasport_seria(){return pasport_seria;};
   QString get_pasport_date(){return pasport_date;};
   int get_pasport_num(){return pasport_num;};
   bool update(int id,QString name,QString surname, QString number, QString email_ardress, QString birthday,QString lat_name,QString lat_surname,QString pasport_seria,QString pasport_date, int pasport_num, QString login, QString password);
};

#endif // CLIENT_H
