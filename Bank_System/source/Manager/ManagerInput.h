#ifndef _MANAGERINPUT_
#define _MANAGERINPUT_

#include <cctype>
#include "OutputFormat.h"
#include "Colors.h"



inline short managerInput()
{
    char choice = std::cin.get();
    clearBuffer();

    while( choice < '1' || choice > '7')
    {
        if (choice == '\n')
            cleanLines(1);

        coloredText( Color::red, "Wrong input, please choose between 1 and 7: " );
        choice = std::cin.get();
        clearBuffer();
        cleanLines(1);
    }

    return short(choice - 48);
}


inline short isManagerContinue()
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



#endif //_MANAGERINPUT_