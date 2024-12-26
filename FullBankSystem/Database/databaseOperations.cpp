#include "databaseOperations.h"
#include <type_traits>


using RequestType = QueryType::Request;
using EnumerationType = std::underlying_type_t<RequestType>;



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


QString DatabaseOperations::get(const QString& firstName, const QString& LastName, QueryType queryType)
{
    QString query;

    switch(static_cast<EnumerationType>(queryType.getRequest()))
    {
        case static_cast<EnumerationType>(RequestType::information):

            break;

        case static_cast<EnumerationType>(RequestType::balance):

            break;

        case static_cast<EnumerationType>(RequestType::history):

            break;

        default:
            break;
    }

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
