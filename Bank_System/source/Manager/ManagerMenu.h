#ifndef _MANAGERMENU_
#define _MANAGERMENU_

#include <stddef.h>
#include "Globals.h"
#include "BankOperations.h"
#include "CustomerOperations.h"
#include "ManagerInput.h"
#include "OutputFormat.h"
#include "Colors.h"


inline size_t managerMenuChoice(short, bool&);


inline bool managerMenu()
{
    coloredText( Color::bgGreen, "Hello Dear Manager!!!");
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

        coloredText( Color::yellow, "Please choose from the following: ");
        newLines(1);

        coloredText( Color::darkGray, "1. List all customers information \n2. List vip customers ");
        coloredText( Color::darkGray, "\n3. List standard customer \n4. List blocked customers");
        coloredText( Color::darkGray, "\n5. Block account \n6. Bank revenue \n7. Exit menu ");
        coloredText( Color::darkGray, "\nPlease choose from 1 to 7: ");
        short managerChoice = managerInput();

        if (managerChoice == 7)
        {
            continueMenu = false;

            linesPrinted += 9;
        }
        else
        {
            linesPrinted = managerMenuChoice(managerChoice, continueMenu);

            coloredText( Color::darkGray, "Want to continue(Y/N): " );
            continueMenu = isManagerContinue();
            
            linesPrinted += 10;

            if( managerChoice == 5)
            {
                linesPrinted += 4;
            }
            else if( managerChoice == 6 )
            {
                linesPrinted++;
            }
        }
    }

    cleanLines(linesPrinted);

    return false;
}



inline size_t managerMenuChoice(short managerChoice, bool& continueMenu)
{
    size_t linesPrinted{0};

    switch (managerChoice)
    {
        case 1:
            linesPrinted = database.printDatabase();
            break;
        case 2:
            linesPrinted = database.printVipCustomers();
            break;
        case 3:
            linesPrinted = database.printStandardCustomers();
            break;
        case 4:
            linesPrinted = blockedCustomers.print();
            break;
        case 5:
            blockCustomer();
            break;
        case 6:
            bankRevenue();
            break;
        default:
            break;
    }

    return linesPrinted;
}




#endif //_MANAGERMENU_