#ifndef CALENDARVIEWMODEL_H
#define CALENDARVIEWMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QDate>
#include "calendarcontroller.h"
#include <QList>

class CalendarViewModel : public QAbstractListModel
{
    Q_OBJECT
    static CalendarViewModel* instance; //singleton için değişken
    explicit CalendarViewModel(QObject *parent = nullptr);
public:

    CalendarViewModel(const CalendarViewModel& obj) = delete;   //kopyalama engelliyor

    static CalendarViewModel* getInstance()
    {
        if(instance == nullptr)
        {
            instance = new CalendarViewModel();
            return instance;
        }
        else
        {
            return instance;
        }
    }
    enum CalendarRoles{
        RECEIPT_NO  = Qt::UserRole +1,
        NAME,
        PAID_AMOUNT,
        DATE
    };

public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
private:
signals:


public slots:
};

#endif // CALENDARVIEWMODEL_H
