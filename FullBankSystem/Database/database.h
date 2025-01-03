#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include "databaseConnectionError.h"
#include "databaseOperations.h"



class Database : public QObject
{
private:
    QSqlDatabase bankDb;
    DatabaseOperations operations;

    Database();
    Database(const Database& obj) = delete;
    Database(Database&& obj) = delete;
    Database& operator=(const Database& rhs) noexcept = delete;
    Database& operator=(Database&& rhs) noexcept = delete;

public:

    static Database& getDatabase();
    DatabaseOperations& operation();

    ~Database() noexcept;
};



#endif // DATABASE_H

