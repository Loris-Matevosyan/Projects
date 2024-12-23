#include "databaseOperations.h"



DatabaseOperations::DatabaseOperations()
{
    start();
}


void DatabaseOperations::start()
{
    QSqlDatabase::database().transaction();
}


void DatabaseOperations::commit()
{
    QSqlDatabase::database().commit();
}


void DatabaseOperations::rollback()
{
    QSqlDatabase::database().rollback();
}


QString DatabaseOperations::get(const QString& firstName, const QString& LastName,QueryType queryType)
{
    QString query;
    return query;
}

bool DatabaseOperations::create(const QString& information)
{
    return true;
}


bool DatabaseOperations::insert(const QString& information)
{
    return true;
}


bool DatabaseOperations::update(const QString& information)
{
    return true;
}


bool DatabaseOperations::erase(const QString& information)
{
    return true;
}
