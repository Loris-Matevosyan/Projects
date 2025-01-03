#ifndef QUERYERROR_H
#define QUERYERROR_H

#include <system_error>
#include <string>


class QueryError : public std::system_error
{
public:
    QueryError()
        : std::system_error(std::make_error_code(std::errc::operation_canceled), "Query failed") {};
    QueryError(const char* text)
        : std::system_error(std::make_error_code(std::errc::operation_canceled), text) {};
    QueryError(const std::string& text)
        : std::system_error(std::make_error_code(std::errc::operation_canceled), text) {};


    QueryError(const QueryError& obj) = default;
    QueryError& operator=(const QueryError& rhs) = default;

};


#endif // QUERYERROR_H
