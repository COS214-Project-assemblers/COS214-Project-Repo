#ifndef AVERAGECUSTOMERCREATOR_H
#define AVERAGECUSTOMERCREATOR_H

#include "CustomerCreator.h"

class AverageCustomerCreator: public CustomerCreator
{
    public:
        AverageCustomerCreator();
        ~AverageCustomerCreator();

        Customer* createCustomer();
};

#endif