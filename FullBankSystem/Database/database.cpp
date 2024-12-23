#include "database.h"


Database::Database() : bankDb(QSqlDatabase::addDatabase("QPSQL"))
{
    bankDb.setHostName("localhost");
    bankDb.setPort(5432);
    bankDb.setDatabaseName("BankSystem");
    bankDb.setUserName("username");
    bankDb.setPassword("password");

    if(!bankDb.open())
    {
        throw DatabaseConnectionError(bankDb.lastError().text().toStdString());
    }

}


Database& Database::getDatabase()
{
    static Database database;
    return database;
}


Database::~Database() noexcept
{
    bankDb.close();
}
