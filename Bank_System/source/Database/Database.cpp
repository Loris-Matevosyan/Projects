#include "Database.h"
#include "DatabaseException.h"
#include "Colors.h"
#include "OutputFormat.h"
#include <iostream>


Database::Database()
{
    databaseWrite.open( "DatabaseFile.txt", std::ios::app );

    databaseRead.open( "DatabaseFile.txt" );
    
    checkDatabaseValidity();

    TemporaryCustomerData tempCustomerData;

    while( !databaseRead.eof() )
    {
        databaseRead >> tempCustomerData.m_firstName;
        databaseRead >> tempCustomerData.m_lastName;
        databaseRead >> tempCustomerData.m_citizenship;
        databaseRead >> tempCustomerData.m_address;
        databaseRead >> tempCustomerData.m_phoneNumber;
        databaseRead >> tempCustomerData.m_balance;

        if( tempCustomerData.m_balance >= 500000 )
            tempCustomerData.m_type = CustomerType::vip;
        else
            tempCustomerData.m_type = CustomerType::standard;
        
        Customer customer{tempCustomerData};

        customersData.insert( { { customer.getFirstName(),
                                  customer.getLastName() },
                                  std::move(customer) } );
    }
}


size_t Database::invalidCustomerName( const std::string& firstName, const std::string& lastName ) const noexcept
{   
    size_t linesPrinted{0};
    
    coloredText( Color::red, "Customer doesn't exist with the name ");
    
    std::string fullName = firstName + " " + lastName;
    coloredText( Color::red, fullName );
    newLines(1);

    linesPrinted = 2;

    return linesPrinted;
    
}


void Database::checkDatabaseValidity()
{
    try
    {
        if ( !databaseWrite.is_open() )
        {
            throw FileOpenException("Error: Database file for writing can't be open");
        }

        if ( !databaseRead.is_open() )
        {
            throw FileOpenException("Error: Database file for reading can't be open");
        }
    }
    catch (const FileOpenException& fileException)
    {
        std::cout << fileException.what() << std::endl;
        std::exit(1);
    }
}


Database& Database::openDatabase()
{
    static Database database;
    
    return database;
}


size_t Database::printDatabase() const noexcept
{
    size_t linesPrinted{0};

    for(const auto& [fullName, customer] : customersData)
    {
        linesPrinted += customer.getInformation();
    }

    return linesPrinted;
}


size_t Database::printVipCustomers() const noexcept
{
    size_t linesPrinted{0};

    for(const auto& [fullName, customer]: customersData)
    {
        if( customer.isVip() )
        {
            linesPrinted += customer.getInformation();
        }
    }

    return linesPrinted;
}


size_t Database::printStandardCustomers() const noexcept
{
    size_t linesPrinted{0};

    for( const auto& [fullName, customer]: customersData )
    {
        if( !customer.isVip() )
        {
            linesPrinted += customer.getInformation();
            
        }
    }

    return linesPrinted;
}


bool Database::findCustomer(const std::string& firstName, const std::string& lastName)
{
    if( bool isCustomer = customersData.contains( {firstName, lastName} ); isCustomer )
        return true;
    
    return false;
}


void Database::addCustomer(Customer&& newCustomer)
{
    customersData.insert( { { newCustomer.getFirstName(), 
                              newCustomer.getLastName() }, 
                              std::move(newCustomer) } );
}


// DRY principle = don't repeat yourself!!!


void Database::deleteCustomer(const std::string& firstName, const std::string& lastName)
{
    auto customerIter = customersData.find( { firstName, lastName} );

    if( customerIter != customersData.end() )
    {
        customersData.erase( customerIter );
    }
    else 
    {  
        invalidCustomerName(firstName, lastName);
    }
}


std::optional<Customer> Database::moveCustomer(const std::string& firstName, const std::string& lastName)
{
    auto customerIter = customersData.find( { firstName, lastName} );

    if( customerIter != customersData.end() )
    {
        return std::move(customerIter->second);
    }
    else 
    {  
        invalidCustomerName(firstName, lastName);
    }

    return std::nullopt;
}


std::optional<std::reference_wrapper<Customer>> Database::getCustomer(const std::string& firstName, const std::string& lastName)
{
    auto customerIter = customersData.find( { firstName, lastName} );

    if( customerIter != customersData.end() )
    {
        return std::ref(customerIter->second);
    }
    else 
    {  
        invalidCustomerName(firstName, lastName);
    }

    return std::nullopt;
}


void Database::customerInfo(const std::string& firstName, const std::string& lastName) const noexcept
{
    auto customerIter = customersData.find( { firstName, lastName } );

    if( customerIter != customersData.end() )
    {
        customerIter->second.getInformation();
    }
    else 
    {  
        invalidCustomerName(firstName, lastName);
    }
}


size_t Database::accountBalance(const std::string& firstName, const std::string& lastName) const noexcept
{
    size_t linesPrinted{0};

    auto customerIter = customersData.find( { firstName, lastName } );

    if( customerIter != customersData.end() )
    {
        std::cout << firstName << " " << lastName << " account balance is " << customerIter->second.getBalance() << "$" << std::endl;
        linesPrinted = 1;
    }
    else 
    {  
        linesPrinted = invalidCustomerName(firstName, lastName);   
    }

    return linesPrinted;
}


Database::~Database() noexcept
{
    databaseWrite.close();
    databaseRead.close();
}