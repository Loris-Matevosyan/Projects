#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "database.h"


int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("BankSystem", "Main");

    try
    {
        Database& databaseOne = Database::getDatabase();
    }
    catch(const DatabaseConnectionError& error)
    {
        qFatal() << error.what();
    }


    return app.exec();
}
