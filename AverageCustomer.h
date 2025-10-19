#ifndef AVERAGECUSTOMER_H
#define AVERAGECUSTOMER_H

#include "Customer.h"

class AverageCustomer: public Customer{
    public:
        //havent added @gerard 's func
        ~AverageCustomer() override=default;
        void accept(CustomerVisitor& cV) override;
        const Plant* considerOptions(const std::vector<const Plant*> offers)const override;
};

#endif