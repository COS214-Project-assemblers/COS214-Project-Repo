#include "AverageCustomerCreator.h"

AverageCustomerCreator::AverageCustomerCreator() : CustomerCreator()
{

}

AverageCustomerCreator::~AverageCustomerCreator()
{

}

Customer* AverageCustomerCreator::createCustomer()
{
    return new AverageCustomer();
}