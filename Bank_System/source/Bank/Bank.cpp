#include "Bank.h"
#include "Greeting.h"
#include "MainMenu.h"
#include "ManagerMenu.h"
#include "CustomerMenu.h"
#include "OutputFormat.h"


void bankLoop()
{
    greeting();

    bool isInBank{true};

    while (isInBank)
    {
        bool isManager = menuSelection();
        bool isCustomer = !isManager;

        cleanLines(4);

        while (isManager) 
        {   
            isManager = managerMenu();

            cleanLines(2);
        }
        
        while (isCustomer)
        {
            isCustomer = customerMenu();

            cleanLines(2);
        }
    }



}