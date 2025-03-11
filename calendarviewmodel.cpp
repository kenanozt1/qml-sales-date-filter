#include "calendarviewmodel.h"
#include <QDebug>
#include <db_transactions.h>
#include "calendarcontroller.h"

CalendarViewModel* CalendarViewModel::instance = nullptr;

CalendarViewModel::CalendarViewModel(QObject *parent) : QAbstractListModel{parent}
{
    Q_UNUSED(parent)
}
int CalendarViewModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return CalendarController::getInstance()->getReceiptInfo().count();
}

QVariant CalendarViewModel::data(const QModelIndex &index, int role) const
{
    QList<QStringList> receipts;

    receipts = CalendarController::getInstance()->getReceiptInfo();

    auto receipt = receipts.at(index.row());
    auto role_enum = static_cast<CalendarRoles>(role);
    qDebug() << "model";
    switch (role_enum) {
    case RECEIPT_NO:
        return receipt[1];
        break;
    case NAME:
        return receipt[0];
        break;
    case DATE:
        return receipt[3];
        break;
    case PAID_AMOUNT:
        return receipt[2];
        break;
        break;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> CalendarViewModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[RECEIPT_NO] = "receipt_no";
    roles[NAME] = "name";
    roles[PAID_AMOUNT] = "paid_amount";
    roles[DATE] = "date_";
    return roles;
}
