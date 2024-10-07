#ifndef _MANAGER_
#define _MANAGER_

#include <string>


class Manager
{
    std::string login;
    std::string password;

public:
    Manager();

    void signIn();
    bool authentication();

};




#endif //_MANAGER_