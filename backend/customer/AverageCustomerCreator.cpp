#include "AverageCustomerCreator.h"

AverageCustomerCreator::AverageCustomerCreator() : CustomerCreator()
{

}

AverageCustomerCreator::~AverageCustomerCreator()
{

}

Customer* AverageCustomerCreator::createCustomer(const CustomerData& data)
{
    return new AverageCustomer(data);
}