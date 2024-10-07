#ifndef _USERINPUT_
#define _USERINPUT_

#include "OutputFormat.h"
#include "Colors.h"


inline short userInput()
{
    char choice = std::cin.get();
    clearBuffer();

    while( choice != '1' && choice != '2')
    {
        if (choice == '\n')
            cleanLines(1);

        coloredText( Color::red, "Wrong input, please choose between 1 or 2: " );
        choice = std::cin.get();
        clearBuffer();
        cleanLines(1);
    }

    if( choice == '1' )
        return true;

    return false;
}



#endif //_USERINPUT_