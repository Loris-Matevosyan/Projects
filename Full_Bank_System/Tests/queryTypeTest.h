#ifndef QUERYTYPETEST_H
#define QUERYTYPETEST_H

#include <QObject>
#include "queryType.h"



class QueryTypeTest : public QObject
{
    Q_OBJECT

public:
    explicit QueryTypeTest(QObject *parent = nullptr);

private slots:

    void checkInformationKey();
    void checkBalanceKey();
    void checkHistoryKey();

    void checkInformationValue();
    void checkBalanceValue();
    void checkHistoryValue();
};



#endif // QUERYTYPETEST_H
