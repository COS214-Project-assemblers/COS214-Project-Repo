#ifndef GREENFINGERCUSTOMERCREATOR_H
#define GREENFINGERCUSTOMERCREATOR_H

#include "CustomerCreator.h"

class GreenFingerCustomerCreator: public CustomerCreator
{
    public:
        GreenFingerCustomerCreator();
        ~GreenFingerCustomerCreator();

        Customer* createCustomer();
};

#endif