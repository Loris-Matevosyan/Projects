#ifndef _OUTPUTFORMAT_
#define _OUTPUTFORMAT_

#include <iostream>
#include <limits>

#define BACKLINE "\033[1A"
#define CLEARLINE "\033[0K"



inline void newLines(int lines)
{
    for( int i = 0; i < lines; ++i )
    {
        std::cout << "\n";
    }
}


inline void cleanLines(int linesToClean)
{
    for( int i = 0; i < linesToClean; ++i )
    {
        std::cout << BACKLINE << CLEARLINE << std::flush; 
    }
}


inline void clearBuffer()
{
    std::cin.clear();
    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
}



#endif //_OUTPUTFORMAT_