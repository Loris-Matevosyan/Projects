#ifndef _CUSTOMEROPERATIONS_
#define _CUSTOMEROPERATIONS_

#include <iostream>
#include <string>
#include <utility>
#include <optional>
#include "Globals.h"
#include "Customer.h"
#include "CustomerInput.h"
#include "OutputFormat.h"
#include "Colors.h"


using FullName = std::pair<std::string, std::string>;


inline void blockCustomer()
{
    std::string firstName;
    std::string lastName;

    coloredText( Color::cyan, "\nEnter customer first name: ");
    std::getline(std::cin, firstName);

    coloredText( Color::cyan, "Enter customer last name: ");
    std::getline(std::cin, lastName);

    std::optional<Customer> customer = database.moveCustomer(firstName, lastName);

    if ( customer.has_value() )
    {
        blockedCustomers.insert( std::move( customer.value() ) );

        database.deleteCustomer(firstName, lastName);
    }

}


inline std::optional<FullName> customerValidation()
{
    bool isValid{false};
    bool isLooping{true};

    while( isLooping ) 
    {
        auto [firstName, lastName] = customerFullName();
        isValid = database.findCustomer( firstName, lastName );

        if( isValid )
        {
            return std::make_pair( firstName, lastName );
        }

        coloredText( Color::red, "Wrong name, please try again\n");
        coloredText( Color::red, "Want to exit or try again (Y/N):");
        isLooping = isCustomerContinue();

        cleanLines(2);
    }

    return std::nullopt;
}


inline size_t deposit( FullName fullName )
{
    size_t linesPrinted{0};
    size_t amount{0};

    std::optional<std::reference_wrapper<Customer>> customerOpt = database.getCustomer( fullName.first, fullName.second );

    if( !customerOpt.has_value() )
    {
        return linesPrinted;
    }

    while ( amount < 1 )
    {
        coloredText( Color::darkGray, "Amount to deposit: ");
        amountInput( amount, linesPrinted );

        if ( amount < 1 )
        {
            coloredText( Color::red, "Wrong amount, please try again\n");
            linesPrinted++;
        }
    }
    
    customerOpt.value().get().deposit(amount);

    return linesPrinted;
}


inline size_t withdrawal( FullName fullName )
{
    size_t linesPrinted{0};
    size_t amount{0};

    std::optional<std::reference_wrapper<Customer>> customerOpt = database.getCustomer( fullName.first, fullName.second );

    if( !customerOpt.has_value() )
    {
        return linesPrinted;
    }

    while ( amount < 1  || amount > customerOpt.value().get().getBalance() )
    {
        coloredText( Color::darkGray, "Amount to withdraw: ");
        amountInput( amount, linesPrinted );

        if ( amount < 1 || amount > customerOpt.value().get().getBalance() )
        {
            coloredText( Color::red, "Wrong amount, please try again\n");
            linesPrinted++;
        }
    }

    customerOpt.value().get().withdrawal(amount);

    return linesPrinted;
}


inline size_t customerMenuChoice(short customerChoice, bool& continueMenu, FullName fullName)
{
    size_t linesPrinted{0};

    switch (customerChoice)
    {
        case 1:
            linesPrinted = database.accountBalance( fullName.first, fullName.second );
            break;
        case 2:
            linesPrinted = deposit( fullName );
            break;
        case 3:
            linesPrinted = withdrawal( fullName );
            break;
        case 4:
            continueMenu = false;
            break;
        default:
            break;
    }

    return linesPrinted;
}



#endif //_CUSTOMEROPERATIONS_