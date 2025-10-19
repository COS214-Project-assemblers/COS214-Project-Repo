#ifndef AVERAGECUSTOMER_H
#define AVERAGECUSTOMER_H

#include "Customer.h"

class AverageCustomer : public Customer
{
    private:
        void showDialog();
        vector<string> compileOptions();
        void processChoice(int choice);

    public:
        AverageCustomer();
        ~AverageCustomer();
        void accept(CustomerVisitor& cV) override;
        const Plant* considerOptions(const std::vector<const Plant*> offers)const override;
};

#endif