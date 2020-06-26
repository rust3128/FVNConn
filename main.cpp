#include "DataBase/database.h"
#include "crtvnconnect.h"

#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QString>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DataBase *db = new DataBase();
    if(!db->connectDB()){
        qDebug() << "Аварийное завершение работы.";
        return 1;
    }
    QTextStream qtin(stdin);
    QString termID = qtin.readLine();  // This is how you read the entire line


    qDebug() << "Test: " << termID;

    CrtVNConnect vnc(termID.toUInt());

    return a.exec();
}
