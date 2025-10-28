#include "CustomerBuilder.h"

CustomerBuilder::CustomerBuilder()
{
    customer = nullptr;
}

CustomerBuilder::~CustomerBuilder()
{
    if (customer != nullptr) 
    {
        delete customer;
    }
}

Customer* CustomerBuilder::getCustomer()
{
    return customer;
}