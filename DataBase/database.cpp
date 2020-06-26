#include "database.h"
#include "GlobalSettings/globalsettings.h"



#include <QDebug>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlError>


DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

bool DataBase::connectDB()
{
    bool result = false;

    QSettings settings(GlobalSettings::CONFIG_FILE_NAME, QSettings::IniFormat);
    QSqlDatabase db = QSqlDatabase::addDatabase("QIBASE");

    //Установка параметров подключения из файла настроек
    settings.beginGroup("DATABASE");
    db.setHostName(settings.value("HostName").toString());
    db.setDatabaseName(settings.value("DataBase").toString());
    db.setUserName(settings.value("User").toString());
    db.setPassword(settings.value("Password").toString());
    settings.endGroup();
    //Открываем базу данных, если попытка не удачная вызываем диалог настроек подключения
    if(!db.open()) {
        qDebug() <<  "Не возможно подключиться к базе данных." << endl << "Причина:" << db.lastError().text();
        //Завершаем работу
        result = false;
    } else {
        qDebug() << "Успешное подключение к центральной базе данных.";
        result = true;
    }


    return result;
}
