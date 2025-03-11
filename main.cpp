#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "db_transactions.h"
#include "calendarviewmodel.h"
#include "calendarcontroller.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    qmlRegisterType<Db_Transactions>("com.manager.database",1,0,"Db_Transactions");

    QQmlApplicationEngine engine;


    engine.rootContext()->setContextProperty(QStringLiteral("db"), Db_Transactions::getInstance());
    engine.rootContext()->setContextProperty(QStringLiteral("calendarModel"), CalendarViewModel::getInstance());
    engine.rootContext()->setContextProperty(QStringLiteral("calendarController"), CalendarController::getInstance());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
