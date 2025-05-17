#ifndef DATABASE_H
#define DATABASE_H

#include <QQmlEngine>
#include <QObject>
#include <QStringList>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include "databaseConnectionError.h"
#include "databaseOperations.h"



class Database : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase bankDb;
    DatabaseOperations operations;

    explicit Database(QObject* parent = nullptr);
    Database(const Database& obj) = delete;
    Database(Database&& obj) = delete;
    Database& operator=(const Database& rhs) noexcept = delete;
    Database& operator=(Database&& rhs) noexcept = delete;

public:

    static Database& getDatabase();
    DatabaseOperations& operation();

    ~Database() noexcept;

public slots:
    Q_INVOKABLE QStringList allCustomers();
    Q_INVOKABLE QStringList vipCustomers();
    Q_INVOKABLE QStringList standardCustomers();
};


static QObject* singletonDatabase(QQmlEngine *, QJSEngine *) {
    return &Database::getDatabase();
}


#endif // DATABASE_H

