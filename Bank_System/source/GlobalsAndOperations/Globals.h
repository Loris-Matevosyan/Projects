#ifndef _GLOBALS_
#define _GLOBALS_

#include "Database.h"
#include "BlockedCustomers.h"


inline Database& database = Database::openDatabase();
inline BlockedCustomers& blockedCustomers = BlockedCustomers::createBlockedCustomers();

inline constexpr double loanInterestRate = 0.06;



#endif //_GLOBALS_