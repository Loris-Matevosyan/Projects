#include "BlockedCustomers.h"
#include "Colors.h"


BlockedCustomers& BlockedCustomers::createBlockedCustomers()
{
    static BlockedCustomers blockedCustomers;
    
    return blockedCustomers;
}


void BlockedCustomers::insert(Customer&& customer)
{
    blockedCustomersList.insert( { { customer.getFirstName(),
                                     customer.getLastName() },
                                     std::move(customer) } );
}


size_t BlockedCustomers::print()
{
    size_t linesPrinted{0};

    if( blockedCustomersList.empty() )
    {
        coloredText( Color::red, "The list is empty\n");
        
        linesPrinted++;
    }
    else
    {
        for(const auto& [fullName, customer]: blockedCustomersList)
        {
            linesPrinted += customer.getInformation();
            
        }
    }

    return linesPrinted;

}