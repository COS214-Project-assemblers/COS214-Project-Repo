#include "GreenFingerCustomerCreator.h"

GreenFingerCustomerCreator::GreenFingerCustomerCreator() : CustomerCreator()
{

}

GreenFingerCustomerCreator::~GreenFingerCustomerCreator()
{

}

Customer* GreenFingerCustomerCreator::createCustomer()
{
    return new GreenFingerCustomer();
}