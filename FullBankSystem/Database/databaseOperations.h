#ifndef DATABASEOPERATIONS_H
#define DATABASEOPERATIONS_H

#include <QSqlDatabase>
#include <QStringList>
#include <QString>
#include <queryType.h>


class DatabaseOperations
{
private:

    void commit();
    void rollback();

public:
    DatabaseOperations();

    void start();

    QString get(const QString& firstName, const QString& lastName, QueryType& queryType);
    QStringList getAll();
    bool create(const QString& information);
    bool insert(const QString& information);
    bool update(const QString& information);
    bool erase(const QString& information);

    ~DatabaseOperations() noexcept = default;

};



#endif // DATABASEOPERATIONS_H

