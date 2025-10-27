#include "GreenFingerCustomerCreator.h"

GreenFingerCustomerCreator::GreenFingerCustomerCreator() : CustomerCreator()
{

}

GreenFingerCustomerCreator::~GreenFingerCustomerCreator()
{

}

Customer* GreenFingerCustomerCreator::createCustomer(const CustomerData& data)
{
    return new GreenFingerCustomer(data);
}