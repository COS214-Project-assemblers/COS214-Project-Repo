#ifndef IGNORANTCUSTOMER_H
#define IGNORANTCUSTOMER_H

#include "Customer.h"

class IgnorantCustomer : public Customer
{
    private:
        void showDialog();
        vector<string> compileOptions();
        void processChoice(int choice);

    public:
        IgnorantCustomer();
        ~IgnorantCustomer();
};

#endif