#ifndef _COLORS_
#define _COLORS_

#include <iostream>
#include <string_view>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define DARKGRAY "\033[90m"

#define BGRED "\033[41m"
#define BGGREEN "\033[42m"
#define BGYELLOW "\033[43m"
#define BGCYAN "\033[46m"

#define RESETCOLORS "\033[0m"



enum class Color
{ 
    red, green, yellow, cyan, darkGray,
    bgRed, bgGreen, bgYellow, bgCyan
};


inline void printAndResetColors(std::string_view text)
{
    std::cout << text << RESETCOLORS << std::flush;
}


inline void coloredText(Color color, std::string_view text)
{
    switch (color)
    {
        case Color::red:
            std::cout << RED;
            printAndResetColors(text);
            break;
        case Color::green:
            std::cout << GREEN;
            printAndResetColors(text);
            break;
        case Color::yellow:
            std::cout << YELLOW;
            printAndResetColors(text);
            break;
        case Color::cyan:
            std::cout << CYAN;
            printAndResetColors(text);
            break;
        case Color::darkGray:
            std::cout << DARKGRAY;
            printAndResetColors(text);
            break;
        case Color::bgRed:
            std::cout << BGRED;
            printAndResetColors(text);
            break;
        case Color::bgGreen:
            std::cout << BGGREEN;
            printAndResetColors(text);
            break;
        case Color::bgYellow:
            std::cout << BGYELLOW;
            printAndResetColors(text);
            break;
        case Color::bgCyan:
            std::cout << BGCYAN;
            printAndResetColors(text);
            break;
        default:
            break;
    }
}




#endif //_COLORS_