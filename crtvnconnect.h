#ifndef CRTVNCONNECT_H
#define CRTVNCONNECT_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>

class CrtVNConnect : public QObject
{
    Q_OBJECT
public:
    explicit CrtVNConnect(uint tID, QObject *parent = nullptr);

signals:

private:

    void getConnString();
private:
    uint terminalID;
    QString connArg;
};

#endif // CRTVNCONNECT_H
