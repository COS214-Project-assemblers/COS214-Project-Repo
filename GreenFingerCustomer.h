#ifndef GREENFINGERCUSTOMER_H
#define GREENFINGERCUSTOMER_H

#include "Customer.h"

class GreenFingerCustomer: public Customer{
    public:
        //havent added @gerard 's func
        ~GreenFingerCustomer() override=default;
        void accept(CustomerVisitor& cV) override;
        const Plant* considerOptions(const std::vector<const Plant*> offers)const override;
};

#endif