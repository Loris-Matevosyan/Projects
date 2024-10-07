#include "Customer.h"
#include <iostream>



Customer::Customer( TemporaryCustomerData tempCustomerData )
    : m_firstName{ tempCustomerData.m_firstName }, 
      m_lastName{ tempCustomerData.m_lastName },
      m_citizenship{ tempCustomerData.m_citizenship },
      m_address{ tempCustomerData.m_address },
      m_phoneNumber{ tempCustomerData.m_phoneNumber },
      m_balance{ tempCustomerData.m_balance },
      m_type{ tempCustomerData.m_type }
{
    //Empty
}


size_t Customer::getInformation() const noexcept
{
    std::cout << "\nName: " << m_firstName << "\nLast name: " << m_lastName <<
    "\nCitizenship: " << m_citizenship << "\nAddress: " << m_address <<
    "\nPhone number: " << m_phoneNumber << "\nBalance: " << m_balance << 
    "\n" << std::endl;

    size_t linesPrinted{8};

    return linesPrinted;
}

std::string Customer::getFirstName() const noexcept
{
    return m_firstName;
}


std::string Customer::getLastName() const noexcept
{
    return m_lastName;
}


size_t Customer::getBalance() const noexcept
{
    return m_balance;
}


void Customer::changeFirstName( std::string changedFirstName )
{
    m_firstName = changedFirstName;
}


void Customer::changeLastName( std::string changedLastName )
{
    m_lastName = changedLastName;
}


void Customer::changeCitizenship( std::string changedCitizenship )
{
    m_citizenship = changedCitizenship;
}


void Customer::changeAddress( std::string changedAddress )
{
    m_address = changedAddress;
}


void Customer::changePhoneNumber( size_t changedPhoneNumber )
{
    m_phoneNumber = changedPhoneNumber;
}


bool Customer::isVip() const noexcept
{
    if( m_type == CustomerType::vip )
        return true;
    
    return false;
}


bool Customer::withdrawal( size_t amount )
{
    if( amount > m_balance )
    {
        return false;
    }
    else
    {
        m_balance -= amount;
    }
    
    return true;
}


void Customer::deposit( size_t amount )
{
    m_balance += amount;
}