#ifndef _GREETING_
#define _GREETING_

#include "OutputFormat.h"
#include "Colors.h"


inline void greeting()
{
    newLines(2);
    coloredText(Color::bgCyan, "=======WELCOME TO THE BANK OF THE WORLD=======");
    newLines(3);
}



#endif //_GREETING_