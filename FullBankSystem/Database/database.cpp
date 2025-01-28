#include "database.h"


Database::Database(QObject* parent) : QObject(parent)
{
    bankDb = QSqlDatabase::addDatabase("QPSQL");
    bankDb.setHostName("localhost");
    bankDb.setPort(5432);
    bankDb.setDatabaseName("BankSystem");
    bankDb.setUserName("username");
    bankDb.setPassword("password");


    try
    {
        if(!bankDb.open())
        {
            throw DatabaseConnectionError(bankDb.lastError().text().toStdString());
        }
    }
    catch(const DatabaseConnectionError& error)
    {
        qFatal() << error.what();
    }


    operations.start();
}


Database& Database::getDatabase()
{
    static Database database;
    return database;
}


DatabaseOperations& Database::operation()
{
    return operations;
}


Database::~Database() noexcept
{
    bankDb.close();
}


QStringList Database::allCustomers()
{
    return operations.getAll();
}


