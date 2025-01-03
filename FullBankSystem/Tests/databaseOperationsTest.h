#ifndef DATABASEOPERATIONSTEST_H
#define DATABASEOPERATIONSTEST_H

#include <QObject>
#include "databaseOperations.h"



class DatabaseOperationsTest : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseOperationsTest(QObject *parent = nullptr);

private slots:

    void getQueryInformation();
    void getQueryBalance();
    void getQueryHistory();

};



#endif // DATABASEOPERATIONSTEST_H
