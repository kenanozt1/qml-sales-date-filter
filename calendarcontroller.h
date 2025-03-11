#ifndef CALENDARCONTROLLER_H
#define CALENDARCONTROLLER_H

#include <QObject>
#include <QDate>
#include <QList>
#include <QSqlQuery>
class CalendarController : public QObject
{
    Q_OBJECT

    static CalendarController* instance; //singleton için değişken

public:
    explicit CalendarController(QObject *parent = nullptr);
    CalendarController(const CalendarController& obj) = delete;   //kopyalama engelliyor

    static CalendarController* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new CalendarController();
            return instance;
        }
        else
        {
            return instance;
        }
    }

    Q_INVOKABLE QDate getBeginDate();
    Q_INVOKABLE void setBeginDate(QDate date);

    Q_INVOKABLE QDate getEndDate();
    Q_INVOKABLE void setEndDate(QDate date);

    Q_INVOKABLE QList<QStringList> getReceiptInfo();

    Q_INVOKABLE QList<QString> getOneReceipt(QString ID);

    Q_INVOKABLE void setSortQueryReceipt(QString sort);
    Q_INVOKABLE QString getSortQueryReceipt();

    Q_INVOKABLE void setCurrentPage(qint32 current);
    Q_INVOKABLE qint32 getCurrentPage();

    Q_INVOKABLE void setLimitSize(qint32 limit);
    Q_INVOKABLE qint32 getLimitSize();

    Q_INVOKABLE qint32 getTotalQueryCount();

private:
    QSqlQuery queryOffset(QSqlQuery query);
    QDate beginDate;
    QDate endDate;
    QDate beginDateLast;
    QDate endDateLast;
    QString sortQueryReceipt = "";

    qint32 currentPage = 1;     //pagination işleminde hangi sayfada bulunulduğu
    qint32 limitSize = 7;       //her bir sayfada kaç tane satır bulunacağı
    qint32 totalQueryCount;
    QSqlQuery query;
signals:

public slots:
};

#endif // CALENDARCONTROLLER_H
