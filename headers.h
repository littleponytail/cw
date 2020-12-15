#pragma once
#ifndef HEADERS_H
#define HEADERS_H
#include<QApplication>
#include<QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <Qdialog>
//#include "user.h"
//#include "client.h"

bool find_first_of(QString in_wich_is_searched, QString what_is_searched);
bool find_first_not_of(QString firststring, QString secondstring);
bool consicst_of_letters_only(QString input);
bool consicst_of_rus_letters_only(QString input);
bool Password_check(QString input);
int qlogincheck (QString login);
int accountcheck (QString login, QString password);
int aaccountcheck (QString login, QString password);
QString part_output (QString string, int from, int to);
#endif // HEADERS_H
