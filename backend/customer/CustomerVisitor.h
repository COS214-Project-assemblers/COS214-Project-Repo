#ifndef CUSTOMERVISITOR_H
#define CUSTOMERVISITOR_h

class IgnorantCustomer;
class AverageCustomer;
class GreenFingerCustomer;

class CustomerVisitor{
    public:
        CustomerVisitor();
        virtual ~CustomerVisitor()=default;
        virtual void visitIgnorantCustomer(IgnorantCustomer& cust)=0;
        virtual void visitAverageCustomer(AverageCustomer& cust)=0;
        virtual void visitGreenfingerCustomer(GreenFingerCustomer& cust)=0;
};      

#endif