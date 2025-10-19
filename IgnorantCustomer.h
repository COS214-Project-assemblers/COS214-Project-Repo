#ifndef IGNORANTCUSTOMER_H
#define IGNORANTCUSTOMER_H

#include "Customer.h"

class IgnorantCustomer: public Customer{
    public:
        //havent added @gerard 's func
        ~IgnorantCustomer() override=default;
        void accept(CustomerVisitor& cV) override;
        const Plant* considerOptions(const std::vector<const Plant*> offers)const override;
};

#endif