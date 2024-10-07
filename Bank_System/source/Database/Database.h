#ifndef _DATABASE_
#define _DATABASE_

#include <fstream>
#include <stddef.h>
#include <functional>
#include <optional>
#include <string>
#include <map>
#include "Customer.h"


// In real world project it would using be relational database (ex. SQL)
// with appropriate software (ex. MySQL, PostgreSQL) 


using CustomerData = std::map<std::pair<std::string, std::string>, Customer>;



class Database
{
    std::ofstream databaseWrite;
    std::ifstream databaseRead;
    CustomerData customersData;

    Database();
    
    void checkDatabaseValidity();
    size_t invalidCustomerName(const std::string& firstName, const std::string& lastName) const noexcept;

public:
    Database(const Database& db) = delete;
    Database& operator=(const Database& db) = delete;
    Database(Database&& db) noexcept = delete;
    Database& operator=(Database&& db) noexcept = delete;

    ~Database() noexcept;

    static Database& openDatabase();

    size_t printDatabase() const noexcept;
    size_t printVipCustomers() const noexcept;
    size_t printStandardCustomers() const noexcept;
    
    std::optional<Customer> moveCustomer(const std::string& firstName, const std::string& lastName);
    std::optional<std::reference_wrapper<Customer>> getCustomer(const std::string& firstName, const std::string& lastName);
    bool findCustomer(const std::string& firstName, const std::string& lastName);
    void addCustomer(Customer&& newCustomer);
    void deleteCustomer(const std::string& firstName, const std::string& lastName);
    

    void customerInfo(const std::string& firstName, const std::string& lastName) const noexcept;
    size_t accountBalance(const std::string& firstName, const std::string& lastName) const noexcept;

};



#endif //_DATABASE_