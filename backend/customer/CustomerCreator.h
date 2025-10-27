#ifndef CUSTOMERCREATOR_H
#define CUSTOMERCREATOR_H

#include "Customer.h"

class CustomerCreator
{
    private:
        Customer* customer;
    
    protected:
        virtual Customer* createCustomer(const CustomerData& data) = 0;

    public:
        CustomerCreator();
        virtual ~CustomerCreator();
        
        void makeCustomer(const CustomerData& data);
        Customer* getCustomer();
};

#endif