#ifndef _CUSTOMERINPUT_
#define _CUSTOMERINPUT_

#include <iostream>
#include <cctype>
#include <utility>
#include <string>
#include "OutputFormat.h"
#include "Colors.h"



inline short customerInput()
{
    char choice = std::cin.get();
    clearBuffer();

    while( choice < '1' || choice > '4')
    {
        if (choice == '\n')
            cleanLines(1);

        coloredText( Color::red, "Wrong input, please choose between 1 and 4: " );
        choice = std::cin.get();
        clearBuffer();
        cleanLines(1);
    }

    return short(choice - 48);
}


inline short isCustomerContinue()
{

    char choice = std::cin.get();
    clearBuffer();

    while( std::toupper(choice) != 'Y' && std::toupper(choice) != 'N')
    {
        if (choice == '\n')
            cleanLines(1);

        coloredText( Color::red, "Wrong input, please choose between Y and N: " );
        choice = std::cin.get();
        clearBuffer();
        cleanLines(1);
    }

    if( std::toupper(choice) == 'Y')
        return true;

    return false;
}


inline std::pair<std::string, std::string> customerFullName()
{
    std::string firstName;
    std::string lastName;

    coloredText( Color::cyan, "Enter customer first name: ");
    std::getline(std::cin, firstName);

    coloredText( Color::cyan, "Enter customer last name: ");
    std::getline(std::cin, lastName);

    cleanLines(2);

    return {firstName, lastName};
}


inline void amountInput(size_t& amount, size_t& linesPrinted)
{
        std::cin >> amount;
        clearBuffer();
         
        if ( linesPrinted > 0 )
        {
            cleanLines(linesPrinted);
            linesPrinted = 0;
        }
        else if ( linesPrinted == 0 )
        {
            cleanLines(1);
        }

        linesPrinted++;
}



#endif //_CUSTOMERINPUT_