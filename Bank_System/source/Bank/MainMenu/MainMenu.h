#ifndef _MAINMENU_
#define _MAINMENU_

#include "UserInput.h"


inline bool menuSelection()
{
    coloredText( Color::yellow, "Please choose how do you want to enter the bank system as:" );
    newLines(1);

    coloredText( Color::darkGray, "1. Manager \n2. Customer \nChoose 1 or 2: " );

    return userInput();
}



#endif //_MAINMENU_