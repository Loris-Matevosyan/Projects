#ifndef _BLOCKEDCUSTOMERS_
#define _BLOCKEDCUSTOMERS_

#include <utility>
#include <stddef.h>
#include <map>
#include "Customer.h"


using BlockedCustomersList = std::map<std::pair<std::string, std::string>, Customer>;



class BlockedCustomers
{
    BlockedCustomersList blockedCustomersList;

    BlockedCustomers() = default;
    
public:
    BlockedCustomers(const BlockedCustomers& bc) = delete;
    BlockedCustomers& operator=(const BlockedCustomers& bc) = delete;
    BlockedCustomers(BlockedCustomers&& bc) noexcept = delete;
    BlockedCustomers& operator=(BlockedCustomers&& bc) noexcept = delete;

    ~BlockedCustomers() noexcept = default;
    
    static BlockedCustomers& createBlockedCustomers();

    void insert(Customer&& customer);
    size_t print();

};




#endif //_BLOCKEDCUSTOMERS_