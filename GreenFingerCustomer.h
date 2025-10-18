#ifndef GREENFINGERCUSTOMER_H
#define GREENFINGERCUSTOMER_H

#include "Customer.h"

class GreenFingerCustomer : public Customer
{
    private:
        void showDialog();
        vector<string> compileOptions();
        void processChoice(int choice);

    public:
        GreenFingerCustomer();
        ~GreenFingerCustomer();
};

#endif