#include "databaseTest.h"
#include <QTest>
#include <type_traits>



DatabaseTest::DatabaseTest(QObject *parent)
    : QObject{parent}
{}


void DatabaseTest::databaseClassCreated()
{
    Database& database = Database::getDatabase();
    QVERIFY(std::is_class_v<std::remove_reference_t<decltype(database)>>);
}


void DatabaseTest::databaseClassNonConstructible()
{
    Database& database = Database::getDatabase();
    QVERIFY(!std::is_default_constructible_v<Database>);
}


void DatabaseTest::databaseClassNonCopyConstructible()
{
    Database& database = Database::getDatabase();
    QVERIFY(!std::is_copy_constructible_v<Database>);
}


void DatabaseTest::databaseClassNonCopyAssignable()
{
    Database& database = Database::getDatabase();
    QVERIFY(!std::is_copy_assignable_v<Database>);
}


void DatabaseTest::databaseClassNonMoveConstructible()
{
    Database& database = Database::getDatabase();
    QVERIFY(!std::is_move_constructible_v<Database>);
}


void DatabaseTest::databaseClassNonMoveAssignable()
{
    Database& database = Database::getDatabase();
    QVERIFY(!std::is_move_assignable_v<Database>);
}


void DatabaseTest::databaseClassIsDestructible()
{
    Database& database = Database::getDatabase();
    QVERIFY(!std::is_move_assignable_v<Database>);
}


void DatabaseTest::databaseClassIsSingleton()
{
    Database& databaseOne = Database::getDatabase();
    Database& databaseTwo = Database::getDatabase();
    QVERIFY(&databaseOne == &databaseTwo);
}




void DatabaseTest::databaseConnected()
{
    Database& database = Database::getDatabase();
    QSqlDatabase currentDatabase = QSqlDatabase::database();
    QVERIFY(currentDatabase.isOpen());
}


void DatabaseTest::databaseErrorWhileConnecting()
{
    Database& database = Database::getDatabase();
    QSqlDatabase currentDatabase = QSqlDatabase::database();
    QVERIFY(!currentDatabase.isOpenError());
}



