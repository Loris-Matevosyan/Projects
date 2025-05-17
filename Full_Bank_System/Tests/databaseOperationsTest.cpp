#include "databaseOperationsTest.h"
#include "database.h"
#include "queryType.h"
#include <QString>
#include <QTest>
#include <type_traits>



DatabaseOperationsTest::DatabaseOperationsTest(QObject *parent)
    : QObject{parent}
{}


void DatabaseOperationsTest::getQueryInformation()
{
    Database& database = Database::getDatabase();
    QString firstName = "John";
    QString lastName = "Smith";
    QueryType queryType = QueryType::Request::information;
    QVERIFY((std::is_same_v<decltype(database.operation().get(firstName, lastName, queryType)), QString>));
}


void DatabaseOperationsTest::getQueryBalance()
{
    Database& database = Database::getDatabase();
    QString firstName = "John";
    QString lastName = "Smith";
    QueryType queryType = QueryType::Request::balance;
    QVERIFY((std::is_same_v<decltype(database.operation().get(firstName, lastName, queryType)), QString>));
}



void DatabaseOperationsTest::getQueryHistory()
{
    Database& database = Database::getDatabase();
    QString firstName = "John";
    QString lastName = "Smith";
    QueryType queryType = QueryType::Request::history;
    QVERIFY((std::is_same_v<decltype(database.operation().get(firstName, lastName, queryType)), QString>));
}

