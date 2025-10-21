#ifndef VISITAVERAGESPENDCUSTOMER_H
#define VISITAVERAGESPENDCUSTOMER_H

#include "CustomerVisitor.h"

class VisitAverageSpendCustomer:public CustomerVisitor{
    public:
        VisitAverageSpendCustomer();
        ~VisitAverageSpendCustomer()=default;
        void visitIgnorantCustomer(IgnorantCustomer& cust)override;
        void visitAverageCustomer(AverageCustomer& cust)override;
        void visitGreenfingerCustomer(GreenFingerCustomer& cust)override;
};      

#endif