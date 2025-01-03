#ifndef DATABASEOPERATIONS_H
#define DATABASEOPERATIONS_H

#include <QSqlDatabase>
#include <QString>
#include <queryType.h>


class DatabaseOperations
{
private:

    void start();
    void commit();
    void rollback();

public:
    DatabaseOperations();


    QString get(const QString& firstName, const QString& lastName, QueryType& queryType);
    bool create(const QString& information);
    bool insert(const QString& information);
    bool update(const QString& information);
    bool erase(const QString& information);





    ~DatabaseOperations() noexcept = default;

};



#endif // DATABASEOPERATIONS_H

