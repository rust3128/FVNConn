#include "crtvnconnect.h"
#include <QVariant>
#include <QDebug>

CrtVNConnect::CrtVNConnect(uint tID, QObject *parent) :
    QObject(parent),
    terminalID(tID)
{
    getConnString();
}

void CrtVNConnect::getConnString()
{
    QSqlQuery *q = new QSqlQuery();
    q->prepare("select t.ownersystem_id from terminals t where t.terminal_id=:terminalID");
    q->bindValue(":terminalID",terminalID);
    q->exec();
    q->next();
    connArg = "azs"+q->value(0).toString()+".unit.local";
    qDebug() << "Adress AZS:" << terminalID  << connArg;

}
