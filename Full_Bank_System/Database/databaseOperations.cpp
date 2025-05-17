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
    // Empty
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
        if( !query.exec(command) )
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

            if( !query.next() )
            {
                doesntExist();
                break;
            }

            if( query.isNull(WITHDRAWAL_COLUMN) )
            {
                ansStream << "Deposit: " << query.value(DEPOSIT_COLUMN).toString() << "\n";
            }
            else
            {
                ansStream << "Withdrawal: " << query.value(WITHDRAWAL_COLUMN).toString() << "\n";
            }

            ansStream << "Operation Time: " << query.value(OPERATION_TIME_COLUMN).toString();


            break;

        default:
            break;
    }

    return answer;
}


QStringList DatabaseOperations::getAll()
{
    #define FIRST_NAME 0
    #define LAST_NAME 1
    #define BALANCE 2
    #define STATUS 3

    QSqlQuery query;
    QString command;
    QTextStream cmdStream(&command);

    QStringList answer;

    cmdStream << "SELECT info.first_name, info.last_name, bal.balance, bal.status" << "\n"
              << "FROM customer_information as info" << "\n"
              << "LEFT OUTER JOIN customer_balance as bal" << "\n"
              << "ON info.customer_id = bal.customer_id";

    if( !query.exec(command) )
    {
        throw QueryError(query.lastError().text().toStdString());
    }

    if( query.next() )
    {
        answer << QString("First name").leftJustified(12, ' ')
                + QString("Last name").leftJustified(15, ' ')
                + QString("Balance").leftJustified(12, ' ')
                + QString("Customer type").leftJustified(15, ' ')
               << "\n";

        do
        {
            answer << query.value(FIRST_NAME).toString().leftJustified(12, ' ')
                    + query.value(LAST_NAME).toString().leftJustified(15, ' ')
                    + query.value(BALANCE).toString().leftJustified(12, ' ')
                    + query.value(STATUS).toString().leftJustified(10, ' ');
        }
        while( query.next() );
    }
    else
    {
        answer << "Database is empty";
    }

    return answer;
}


QStringList DatabaseOperations::getCustomers(const QString& customerType)
{
#define FIRST_NAME 0
#define LAST_NAME 1
#define BALANCE 2

    QSqlQuery query;
    QString command;
    QTextStream cmdStream(&command);

    QStringList answer;

    cmdStream << "SELECT info.first_name, info.last_name, bal.balance" << "\n"
              << "FROM customer_information as info" << "\n"
              << "LEFT OUTER JOIN customer_balance as bal" << "\n"
              << "ON info.customer_id = bal.customer_id" << "\n"
              << QString("WHERE bal.status = '%1'").arg(customerType);

    if( !query.exec(command) )
    {
        throw QueryError(query.lastError().text().toStdString());
    }

    if( query.next() )
    {
        answer << QString("First name").leftJustified(12, ' ')
                + QString("Last name").leftJustified(15, ' ')
                + QString("Balance").leftJustified(12, ' ')
               << "\n";

        do
        {
            answer << query.value(FIRST_NAME).toString().leftJustified(12, ' ')
                    + query.value(LAST_NAME).toString().leftJustified(15, ' ')
                    + query.value(BALANCE).toString().leftJustified(12, ' ');
        }
        while( query.next() );
    }
    else
    {
        answer << "Database is empty";
    }

    return answer;
}


QStringList DatabaseOperations::getVip()
{
    return getCustomers("vip");
}


QStringList DatabaseOperations::getStandard()
{
    return getCustomers("standard");
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
