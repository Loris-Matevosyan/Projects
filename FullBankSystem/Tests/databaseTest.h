#ifndef DATABASETEST_H
#define DATABASETEST_H

#include <QObject>
#include "Database.h"



class DatabaseTest: public QObject
{
    Q_OBJECT

public:
    explicit DatabaseTest(QObject *parent = nullptr);

private slots:

    void databaseClassCreated();
    void databaseClassNonConstructible();
    void databaseClassNonCopyConstructible();
    void databaseClassNonCopyAssignable();
    void databaseClassNonMoveConstructible();
    void databaseClassNonMoveAssignable();
    void databaseClassIsDestructible();
    void databaseClassIsSingleton();

    void databaseConnected();
    void databaseErrorWhileConnecting();

};



#endif // DATABASETEST_H
