#ifndef VISITMEDIUMCUSTOMER_H
#define VISITMEDIUMCUSTOMER_h

#include "CustomerVisitor.h"

class VisitMediumCustomer:public CustomerVisitor{
    public:
        VisitMediumCustomer();
        ~VisitMediumCustomer()=default;
        void visitIgnorantCustomer(IgnorantCustomer& cust)override;
        void visitAverageCustomer(AverageCustomer& cust)override;
        void visitGreenfingerCustomer(GreenFingerCustomer& cust)override;
};      

#endif