#ifndef _CUSTOMER_
#define _CUSTOMER_

#include <string>
#include <stddef.h>



enum class CustomerType
{
    standard, vip
};


struct TemporaryCustomerData
{    
    CustomerType m_type;
    std::string m_firstName;
    std::string m_lastName;
    std::string m_citizenship;
    std::string m_address;
    size_t m_phoneNumber;
    size_t m_balance;
};



class Customer
{
    CustomerType m_type;
    std::string m_firstName;
    std::string m_lastName;
    std::string m_citizenship;
    std::string m_address;
    size_t m_phoneNumber;
    size_t m_balance;
    
public:
    Customer( TemporaryCustomerData tempCustomerData) ;
    Customer( const Customer& other ) = default;
    Customer& operator=( const Customer& other ) = default;
    Customer( Customer&& other ) noexcept = default;
    Customer& operator=( Customer&& other ) = default;
    ~Customer() noexcept = default;

    std::string getFirstName() const noexcept;
    std::string getLastName() const noexcept;
    size_t getBalance() const noexcept;
    size_t getInformation() const noexcept;

    void changeFirstName( std::string changedFirstName );
    void changeLastName( std::string changedLastName );
    void changeCitizenship( std::string changedCitizenship );
    void changeAddress( std::string changedAddress );
    void changePhoneNumber( size_t changedNumber );
    
    bool isVip() const noexcept;
    bool withdrawal( size_t amount );
    void deposit( size_t amount );

};




#endif //_CUSTOMER_