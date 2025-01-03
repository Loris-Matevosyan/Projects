#include "databaseOperations.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QTextStream>
#include <QString>
#include "queryError.h"

#define FIRST_NAME_COLUMN 1
#define LAST_NAME_COLUMN 2
#define CITIZENSHIP_COLUMN 3
#define ADDRESS_COLUMN 4
#define PHONE_NUMBER_COLUMN 5
#define EMAIL_COLUMN 6

#define BALANCE_COLUMN 1
#define STATUS_COLUMN 2

#define WITHDRAWAL_COLUMN 1
#define DEPOSIT_COLUMN 2
#define OPERATION_TIME_COLUMN 3


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


QString DatabaseOperations::get(const QString& firstName, const QString& lastName, QueryType& queryType)
{
    QSqlQuery query;

    QString command;
    QTextStream cmdStream(&command);

    QString answer;
    QTextStream ansStream(&answer);

    ansStream << "Name: " << firstName << "\n"
              << "Last Name: " << lastName << "\n";

    auto checkExecution = [&]()
    {
        if(!query.exec(command))
            {
                throw QueryError(query.lastError().text().toStdString());
            }
    };

    auto doesntExist = [&]()
    {
        ansStream << "Customer doesn't exist";
    };

    switch(static_cast<EnumerationType>(queryType.getRequest()))
    {
        case static_cast<EnumerationType>(RequestType::information):

            cmdStream << "SELECT * FROM customer_information ";
            cmdStream << QString("WHERE first_name = '%1' AND last_name = '%2';").arg(firstName, lastName);

            checkExecution();

            if( query.next() )
            {
                ansStream << "Citizenship: " << query.value(CITIZENSHIP_COLUMN).toString() << "\n"
                          << "Address: " << query.value(ADDRESS_COLUMN).toString() << "\n"
                          << "Phone number: " << query.value(PHONE_NUMBER_COLUMN).toString() << "\n"
                          << "Email: " << query.value(EMAIL_COLUMN).toString();
            }
            else
            {
                doesntExist();
            }

            break;

        case static_cast<EnumerationType>(RequestType::balance):

            cmdStream << "SELECT bal.* FROM customer_balance AS bal" << "\n"
                      << "LEFT OUTER JOIN customer_information AS info" << "\n"
                      << "ON bal.customer_id = info.customer_id" << "\n"
            << QString(  "WHERE info.first_name = '%1' AND info.last_name = '%2';"  ).arg(firstName, lastName);

            checkExecution();

            if( query.next() )
            {
                ansStream << "Balance: " << query.value(BALANCE_COLUMN).toString() << "\n"
                          << "Status: " << query.value(STATUS_COLUMN).toString();
            }
            else
            {
                doesntExist();
            }

            break;

        case static_cast<EnumerationType>(RequestType::history):

            cmdStream << "SELECT oper.* FROM customer_operations AS oper" << "\n"
                      << "LEFT OUTER JOIN customer_information AS info" << "\n"
                      << "ON oper.customer_id = info.customer_id" << "\n"
            << QString(  "WHERE info.first_name = '%1' AND last_name = '%2';"  ).arg(firstName, lastName);

            checkExecution();

            if( query.next() )
            {
                if( query.isNull(1) )
                {
                    ansStream << "Deposit: " << query.value(DEPOSIT_COLUMN).toString() << "\n";
                }
                else
                {
                    ansStream << "Withdrawal: " << query.value(WITHDRAWAL_COLUMN).toString() << "\n";
                }

                ansStream << "Operation Time: " << query.value(OPERATION_TIME_COLUMN).toString();
            }
            else
            {
                doesntExist();
            }

            break;

        default:
            break;
    }



    return answer;
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
