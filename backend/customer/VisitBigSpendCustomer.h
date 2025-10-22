#ifndef VISITBIGSPENDCUSTOMER_H
#define VISITBIGSPENDCUSTOMER_h

#include "CustomerVisitor.h"

class VisitBigSpendCustomer:public CustomerVisitor{
    public:
        VisitBigSpendCustomer();
        ~VisitBigSpendCustomer()=default;
        void visitIgnorantCustomer(IgnorantCustomer& cust)override;
        void visitAverageCustomer(AverageCustomer& cust)override;
        void visitGreenfingerCustomer(GreenFingerCustomer& cust)override;
};      

#endif