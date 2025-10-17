#ifndef IGNORANTCUSTOMERCREATOR_H
#define IGNORANTCUSTOMERCREATOR_H

#include "CustomerCreator.h"
#include "IgnorantCustomer.h"

class IgnorantCustomerCreator: public CustomerCreator
{
    public:
        IgnorantCustomerCreator();
        ~IgnorantCustomerCreator();

        Customer* createCustomer();
};

#endif