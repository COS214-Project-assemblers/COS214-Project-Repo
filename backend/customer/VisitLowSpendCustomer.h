#ifndef VISITLOWSPENDCUSTOMER_H
#define VISITLOWSPENDCUSTOMER_h

#include "CustomerVisitor.h"

class VisitLowSpendCustomer:public CustomerVisitor{
    public:
        VisitLowSpendCustomer();
        ~VisitLowSpendCustomer()=default;
        void visitIgnorantCustomer(IgnorantCustomer& cust)override;
        void visitAverageCustomer(AverageCustomer& cust)override;
        void visitGreenfingerCustomer(GreenFingerCustomer& cust)override;
};      

#endif