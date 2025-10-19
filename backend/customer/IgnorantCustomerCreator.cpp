#include "IgnorantCustomerCreator.h"

IgnorantCustomerCreator::IgnorantCustomerCreator()
{
   
    
}

IgnorantCustomerCreator::~IgnorantCustomerCreator()
{

}

Customer* IgnorantCustomerCreator::createCustomer()
{
    return new IgnorantCustomer();
}