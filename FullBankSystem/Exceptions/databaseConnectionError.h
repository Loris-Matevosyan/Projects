#ifndef DATABASECONNECTIONERROR_H
#define DATABASECONNECTIONERROR_H

#include <system_error>
#include <string>


class DatabaseConnectionError : public std::system_error
{
public:
    DatabaseConnectionError()
        : std::system_error(std::make_error_code(std::errc::not_connected), "Unable to connect") {};
    DatabaseConnectionError(const char* text)
        : std::system_error(std::make_error_code(std::errc::not_connected), text) {};
    DatabaseConnectionError(const std::string& text)
        : std::system_error(std::make_error_code(std::errc::not_connected), text) {};


    DatabaseConnectionError(const DatabaseConnectionError& obj) = default;
    DatabaseConnectionError& operator=(const DatabaseConnectionError& rhs) = default;

};



#endif // DATABASECONNECTIONERROR_H

