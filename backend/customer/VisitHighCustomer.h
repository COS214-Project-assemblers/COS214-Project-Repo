#ifndef VISITHIGHCUSTOMER_H
#define VISITHIGHCUSTOMER_h

#include "CustomerVisitor.h"

class VisitHighCustomer:public CustomerVisitor{
    public:
        VisitHighCustomer();
        ~VisitHighCustomer()=default;
        void visitIgnorantCustomer(IgnorantCustomer& cust)override;
        void visitAverageCustomer(AverageCustomer& cust)override;
        void visitGreenfingerCustomer(GreenFingerCustomer& cust)override;
};      

#endif