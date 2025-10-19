#include "CustomerCreator.h"

CustomerCreator::CustomerCreator()
{

}

CustomerCreator::~CustomerCreator()
{

}

void CustomerCreator::makeCustomer()
{
    customer = createCustomer();
}

Customer* CustomerCreator::getCustomer()
{
    return customer;
}