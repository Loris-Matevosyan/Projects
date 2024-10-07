#ifndef _CUSTOMERMENU_
#define _CUSTOMERMENU_


#include <stddef.h>
#include <string>
#include <optional>
#include "CustomerOperations.h"
#include "CustomerInput.h"
#include "OutputFormat.h"
#include "Colors.h"


inline size_t customerOperation(short, bool&);


inline bool customerMenu()
{
    std::string firstName;
    std::string lastName;

    std::optional<std::pair<std::string, std::string>> fullNameOpt = customerValidation();

    if ( !fullNameOpt.has_value() )
    {
        return false;
    }
    else
    {
        firstName = fullNameOpt.value().first;
        lastName = fullNameOpt.value().second;
    }

    std::string fullName = firstName + " " + lastName;
    coloredText( Color::bgYellow, "Hello ");
    coloredText( Color::bgYellow, fullName);

    newLines(2);

    size_t linesPrinted{0};
    bool continueMenu{true};
    
    while (continueMenu)
    {
        if (linesPrinted != 0)
        {
            cleanLines(linesPrinted);
            linesPrinted = 0;
        }

        coloredText( Color::darkGray, "Please choose from the following: ");
        newLines(1);

        coloredText( Color::darkGray, "1. Balance \n2. Deposit \n3. Withdrawal \n4. Exit menu");
        coloredText( Color::darkGray, "\nPlease choose from 1 to 4: ");
        short customerChoice = customerInput();

        if (customerChoice == 4)
        {
            continueMenu = false;
            
            linesPrinted += 6;
        }
        else
        {
            linesPrinted = customerMenuChoice(customerChoice, continueMenu, fullNameOpt.value());

            coloredText( Color::darkGray, "Want to continue(Y/N): " );
            continueMenu = isCustomerContinue();
            
            linesPrinted += 6;
        }

        if (customerChoice == 1)
        {
            linesPrinted++;
        }

    }

    cleanLines(linesPrinted);

    return false;
}




#endif //_CUSTOMERMENU_