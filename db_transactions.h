#ifndef DB_TRANSACTIONS_H
#define DB_TRANSACTIONS_H

#include <QObject>
#include <QSqlDatabase>
class Db_Transactions : public QObject
{
    Q_OBJECT
    static Db_Transactions* instance;
public:
    explicit Db_Transactions(QObject *parent = nullptr);
    Db_Transactions(const Db_Transactions& obj) = delete;
    static Db_Transactions* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new Db_Transactions();
            return instance;
        }
        else
        {
            return instance;
        }
    }

    ~Db_Transactions();
    void connect();
    QSqlQuery select(QString queryString);
    void close();

public:
    QSqlDatabase db;
signals:

public slots:
};

#endif // DB_TRANSACTIONS_H




