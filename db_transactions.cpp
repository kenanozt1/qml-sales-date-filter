#include "db_transactions.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

Db_Transactions* Db_Transactions::instance = nullptr;
Db_Transactions::Db_Transactions(QObject *parent) : QObject(parent)
{
    Q_UNUSED(parent)
    connect();
}

Db_Transactions::~Db_Transactions()
{
   close();
}

void Db_Transactions::connect()
{
    if(!db.isValid())
        db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/exec/acr_main.db");
    if(!db.open()){
        db.close();
        return;
    }
    qDebug() << "Veri tabanı bağlantısı başarılıı";
}

QSqlQuery Db_Transactions::select(QString queryString)
{
    QSqlQuery query(Db_Transactions::getInstance()->db);
    if(!db.isOpen())
        qDebug()<<"Error :"+query.lastError().text();

    if(!query.exec(queryString)){
        qDebug()<<"Error :"+query.lastError().text();
    }
    return query;
}

void Db_Transactions::close()
{
    if(db.isOpen())
        db.close();
}
