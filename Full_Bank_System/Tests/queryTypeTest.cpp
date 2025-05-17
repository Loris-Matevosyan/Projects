#include "queryTypeTest.h"
#include <QTest>


QueryTypeTest::QueryTypeTest(QObject *parent)
    : QObject{parent}
{}


void QueryTypeTest::checkInformationKey()
{
    QueryType queryType(QueryType::Request::information);
    QVERIFY(queryType.toString() == "information");
}


void QueryTypeTest::checkBalanceKey()
{
    QueryType queryType(QueryType::Request::balance);
    QVERIFY(queryType.toString() == "balance");
}


void QueryTypeTest::checkHistoryKey()
{
    QueryType queryType(QueryType::Request::history);
    QVERIFY(queryType.toString() == "history");
}


void QueryTypeTest::checkInformationValue()
{
    QueryType queryType(QueryType::Request::information);
    QVERIFY(queryType.toInt() == 0);
}


void QueryTypeTest::checkBalanceValue()
{
    QueryType queryType(QueryType::Request::balance);
    QVERIFY(queryType.toInt() == 1);
}


void QueryTypeTest::checkHistoryValue()
{
    QueryType queryType(QueryType::Request::history);
    QVERIFY(queryType.toInt() == 2);
}

