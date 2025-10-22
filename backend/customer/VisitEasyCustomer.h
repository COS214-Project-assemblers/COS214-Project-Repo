#ifndef VISITEASYCUSTOMER_H
#define VISITEASYCUSTOMER_H

#include "CustomerVisitor.h"

#include <random>

class VisitEasyCustomer:public CustomerVisitor{
    public:
        VisitEasyCustomer();
        ~VisitEasyCustomer()=default;
        void visitIgnorantCustomer(IgnorantCustomer& cust)override;
        void visitAverageCustomer(AverageCustomer& cust)override;
        void visitGreenfingerCustomer(GreenFingerCustomer& cust)override;
};      

#endif