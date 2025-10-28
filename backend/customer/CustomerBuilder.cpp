#include "CustomerBuilder.h"

CustomerBuilder::CustomerBuilder()
{
    customer = nullptr;
}

CustomerBuilder::~CustomerBuilder()
{
    // customers will be deleted in Game.cpp
}

Customer* CustomerBuilder::getCustomer()
{
    return customer;
}