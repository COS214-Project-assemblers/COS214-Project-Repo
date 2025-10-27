#include "CustomerCreator.h"

CustomerCreator::CustomerCreator()
{
    customer = nullptr;
}

CustomerCreator::~CustomerCreator()
{
    if (customer != nullptr) 
    {
        delete customer;
    }
}

void CustomerCreator::makeCustomer(const CustomerData& data)
{
    customer = createCustomer(data);
}

Customer* CustomerCreator::getCustomer()
{
    return customer;
}