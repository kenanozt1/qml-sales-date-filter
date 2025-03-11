#include "calendarcontroller.h"
#include <QDebug>
#include "db_transactions.h"
#include <QSqlQuery>
#include <QDate>
CalendarController* CalendarController::instance = nullptr;
CalendarController::CalendarController(QObject *parent) : QObject(parent)
{
    Q_UNUSED(parent)
}

QDate CalendarController::getBeginDate()
{
    return beginDate;
}

void CalendarController::setBeginDate(QDate date)
{
    beginDate = date;
}

QDate CalendarController::getEndDate()
{
    return endDate;
}

void CalendarController::setEndDate(QDate date)
{
    endDate = date;
}

//QList<QStringList> CalendarController::getReceiptInfo()
//{
//    result.clear();
//    auto db = Db_Transactions::getInstance();
//    auto controller = CalendarController::getInstance();

//    QString countQueryString = "SELECT COUNT(*) AS total_count FROM getReceiptInfo WHERE date_ BETWEEN '"+beginDate.toString("yyyy-MM-dd")+"' AND '"+endDate.toString("yyyy-MM-dd")+"'";
//    QSqlQuery countQuery = db->select(countQueryString);
//    if(countQuery.next()){
//        totalQueryCount = countQuery.value("total_count").toInt();
//    }
//    QSqlQuery query;
//    QString queryString = "SELECT * FROM getReceiptInfo WHERE date_ BETWEEN '"+beginDate.toString("yyyy-MM-dd")+"' AND '"+endDate.toString("yyyy-MM-dd")+"'";
//    if(sortQueryReceipt != "")
//        queryString += " ORDER BY paid_amount " + sortQueryReceipt;
//    queryString += " LIMIT "+QString::number(limitSize)+" OFFSET "+QString::number(limitSize*(currentPage-1));
//    qDebug() << queryString;
//    query = db->select(queryString);
//    if(controller->getBeginDate().isValid() && controller->getEndDate().isValid()){
//        while(query.next()){
//            QStringList row;
//            row.append(query.value("name").toString());
//            row.append(query.value("receipt_no").toString());
//            row.append(query.value("paid_amount").toString());
//            row.append(query.value("date_").toString());
//            result.append(row);
//        }
//    }else {
//        qDebug() << "HATA! Tarihleri Kontrol Et";
//    }
//    return result;
//}
//-----------------------------------------------------------------------------------------------------------------------------------------
QList<QStringList> CalendarController::getReceiptInfo()
{
    QList<QStringList> result;
    static QList<QStringList> cachedData; // Static cache for the entire dataset

    // Check if date range has changed - only make a new query if necessary
    if(beginDate != beginDateLast || endDate != endDateLast) {
        // Date range changed, need to fetch new data
        auto db = Db_Transactions::getInstance();

        // Get total count for pagination
        QString countQueryString = "SELECT COUNT(*) AS total_count FROM getReceiptInfo WHERE date_ BETWEEN '" +
                beginDate.toString("yyyy-MM-dd") + "' AND '" +
                endDate.toString("yyyy-MM-dd") + "'";
        QSqlQuery countQuery = db->select(countQueryString);
        if(countQuery.next()) {
            totalQueryCount = countQuery.value("total_count").toInt();
        }

        // Fetch ALL data for the date range (no LIMIT or OFFSET)
        QString queryString = "SELECT name,receipt_no,paid_amount,date_ FROM getReceiptInfo WHERE date_ BETWEEN '" +
                beginDate.toString("yyyy-MM-dd") + "' AND '" +
                endDate.toString("yyyy-MM-dd") + "'";

        QSqlQuery query = db->select(queryString);

        // Clear the previous cache and populate with new data
        cachedData.clear();

        if(query.exec()) {
            while(query.next()) {
                QStringList row;
                row << query.value("name").toString()
                    << query.value("receipt_no").toString()
                    << query.value("paid_amount").toString()
                    << query.value("date_").toString();
                cachedData.append(row);
            }
        }
        // Update the date range cache
        beginDateLast = beginDate;
        endDateLast = endDate;
    }

    // At this point, cachedData contains all rows for the current date range
    // Apply sorting (if needed)
    if(!sortQueryReceipt.isEmpty()) {
        // Sort the cached data
        if(sortQueryReceipt.toLower() == "asc") {
            std::sort(cachedData.begin(), cachedData.end(),
                      [](const QStringList &a, const QStringList &b) {
                return a[2].toDouble() < b[2].toDouble(); // paid_amount is at index 2
            });
        } else if(sortQueryReceipt.toLower() == "desc") {
            std::sort(cachedData.begin(), cachedData.end(),
                      [](const QStringList &a, const QStringList &b) {
                return a[2].toDouble() > b[2].toDouble(); // paid_amount is at index 2
            });
        }
    }else{
        std::sort(cachedData.begin(), cachedData.end(),
                  [](const QStringList &a, const QStringList &b) {
            return a[1].toDouble() < b[1].toDouble(); // receipt_no is at index 1
        });
    }

    // Apply pagination to the sorted cached data
    int startIndex = limitSize * (currentPage - 1);
    int endIndex = qMin(startIndex + limitSize, cachedData.size());

    // Make sure we don't go out of bounds
    if(startIndex < cachedData.size()) {
        for(int i = startIndex; i < endIndex; i++) {
            result.append(cachedData[i]);
        }
    }
    return result;
}

QList<QString> CalendarController::getOneReceipt(QString ID)
{
    QList<QString> result;
    auto db = Db_Transactions::getInstance();
    QString queryString = "SELECT * FROM getReceiptInfo WHERE receipt_no = "+ID;

    QSqlQuery query = db->select(queryString);

    if(query.exec()) {
        while(query.next()) {
            QStringList row;
            row << query.value("name").toString()
                << query.value("receipt_no").toString()
                << query.value("paid_amount").toString()
                << query.value("date_").toString()
                << query.value("unit").toString()
                << query.value("unit_price").toString()
                << query.value("liter").toString()
                << query.value("amount").toString()
                << query.value("rate_value").toString()
                << query.value("vat_amount").toString()
                << query.value("explanation").toString()
                << query.value("fic").toString()
                << query.value("iic").toString();
            result.append(row);
        }
    }
    return result;
}

void CalendarController::setSortQueryReceipt(QString sort)
{
    sortQueryReceipt = sort;
}

QString CalendarController::getSortQueryReceipt()
{
    return sortQueryReceipt;
}

void CalendarController::setCurrentPage(qint32 current)
{
    currentPage = current;
}

qint32 CalendarController::getCurrentPage()
{
    return currentPage;
}

void CalendarController::setLimitSize(qint32 limit)
{
    limitSize = limit;
}

qint32 CalendarController::getLimitSize()
{
    return limitSize;
}

qint32 CalendarController::getTotalQueryCount()
{
    return totalQueryCount;
}

