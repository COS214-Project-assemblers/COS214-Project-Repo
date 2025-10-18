#ifndef CUSTOMERCREATOR_H
#define CUSTOMERCREATOR_H

#include "Customer.h"

class CustomerCreator
{
    private:
        Customer* customer;
    
    protected:
        virtual Customer* createCustomer() = 0;

    public:
        CustomerCreator();
        virtual ~CustomerCreator();
        
        void makeCustomer();
        Customer* getCustomer();
};

#endif