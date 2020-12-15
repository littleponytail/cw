
#pragma once
#ifndef EXURSION_H
#define EXURSION_H
#include"headers.h"
class excursion {
    float price;
    float rate;
    int ex_id;
    int people_amount;
    int transport_type; //0-plane, 1-train, 2- bus, 3-plane+ship, 4-plain+train, 5-plane+bus, 6-ship+train, 7-ship+bus
int nights_amount;
    QString 	exursion_description;
    QString arrival_dates;
    QString icon_path;
    QString country;
    QString name;
    int hotel_rate;
    QString meals;
    QString hotel_name;
    QString description;
    QString departure_time;
    QString departure_place;
    QString arrivel_time;
public:
    excursion();
    excursion( int hotel_rate,  int transport,  QString country,  QString meals, int nights_amount, float rate,QString hotel_name,
    QString name, QString arrival_dates);
    excursion(QString escountry, QString esname, QString eshotel_rate, QString espicture_path, QString esprice, QString esmeals);

    QString get_country_name(){return country;};
    float get_price(){return price;};
    int get_hotel_rate(){return hotel_rate;};
    QString get_name(){return name;};
    QString get_meals(){return meals;};
    QString get_picture_path(){return icon_path;};
    int get_id(){return ex_id;};
    float get_rate(){return rate;};
    int get_transport_type(){return transport_type;}
    int get_people_amount(){return people_amount;};
    QString get_desription(){return description; };
    QString get_arrival_date(){return arrival_dates;};
    QString get_hotel_name(){return hotel_name;};
    int set_info(int id);
    int get_nights_amount(){return nights_amount;};
    QString get_deparure_time(){return departure_time;};
    QString get_deparure_place(){return departure_place;};
    QString get_arrivel_time() {return arrivel_time;};
};
 int last_id();
 int first_id();
 int next_id();
 QString * countrys_search();
#endif // EXURSION_H
