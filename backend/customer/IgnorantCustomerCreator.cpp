#include "IgnorantCustomerCreator.h"

IgnorantCustomerCreator::IgnorantCustomerCreator()
{
   
    
}

IgnorantCustomerCreator::~IgnorantCustomerCreator()
{

}

Customer* IgnorantCustomerCreator::createCustomer(const CustomerData& data)
{
    return new IgnorantCustomer(data);
}