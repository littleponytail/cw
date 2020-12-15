#include "authorization_window.h"
#include "headers.h"
#include "headband.h"
#include "client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
       db.setHostName("localhost");
       db.setUserName("root");
       db.setPassword("root");
       db.setPort(3307);
       db.setDatabaseName("clent");
    //   HeadBand window;
     //  window.show();
       //window.close();
       authorization_window w;
       w.show();

    return a.exec();
}
bool find_first_of(QString in_wich_is_searched, QString what_is_searched){
 for (int i=0; i<what_is_searched.length(); i++) if(in_wich_is_searched.contains(what_is_searched[i])) return true;
 return false;
}
bool find_first_not_of(QString in_wich_is_searched, QString what_is_searched){
    for (int i=0; i<what_is_searched.length(); i++) if(!(in_wich_is_searched.contains(what_is_searched[i]))) return true;
    return false;
   }
bool consicst_of_letters_only(QString input){ if (find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGJHIJKLMNOPQRSTUVWXYZ", input))return false;
                                  else return true;};
bool Password_check(QString input) {
    int  n=input.length();
    bool lowercase_letters_presence = false, upperrcase_letters_presence = false;
    bool numbers_presence = false;
    QString Lowercase = "abcdefghijklmnopqrstuvwxyz";
    QString Upercase="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString digits="0123456789";
    if (find_first_of(input, Lowercase))lowercase_letters_presence = true;
    if(find_first_of(input, Upercase))upperrcase_letters_presence = true;
    if(find_first_of(input, digits))numbers_presence = true;
      if ((lowercase_letters_presence || upperrcase_letters_presence) && numbers_presence && (n >= 6)) return true;
        else return false;
};
int qlogincheck (QString login){
       QSqlDatabase db1=QSqlDatabase::database();
    if (!db1.open())return -1;
    QSqlQuery query1= QSqlQuery(db1);
    if (!query1.exec("SELECT LOGIN FROM clients_base") ){db1.close();return 1; }
    while(query1.next())if(query1.value("LOGIN")==login){db1.close();return 0; }
    db1.close();
    return 1;
};
int accountcheck (QString login, QString password){
       QSqlDatabase db2=QSqlDatabase::database();

                            if (!db2.open())return -2;
                           QSqlQuery query= QSqlQuery(db2);
                           if (!query.exec("SELECT * FROM clients_base") ){db2.close();return -1;}
                          while(query.next())if(query.value("LOGIN")==login)
                          { if(query.value("PASSWORD")==password){
                                 db2.close(); return 0;}
                          else{ db2.close(); return 1; };}
                          return 2;

  };


int aaccountcheck (QString login, QString password){
       QSqlDatabase db2=QSqlDatabase::database();

                            if (!db2.open())return -2;
                           QSqlQuery query= QSqlQuery(db2);
                           if (!query.exec("SELECT * FROM admin_base") ){db2.close();return -1;}
                          while(query.next())if(query.value("LOGIN")==login)
                          { if(query.value("PASSWORD")==password){
                                 db2.close(); return 0;}
                          else{ db2.close(); return 1; };}
                          return 2;

  };
QString part_output(QString string, int from, int to) {
    QString output;
    if( from>to|| from>string.length()||to>string.length()) return nullptr;
    for(int i=0; i<to-from;i++){output[i]=string[from+i];};
    return output;
}
bool consicst_of_rus_letters_only(QString input){if (find_first_not_of("абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩ", input))return false;
    else return true;
}
