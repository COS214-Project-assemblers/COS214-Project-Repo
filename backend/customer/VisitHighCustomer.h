#ifndef VISITHIGHCUSTOMER_H
#define VISITHIGHCUSTOMER_h

#include "CustomerVisitor.h"

class VisitHighCustomer:public CustomerVisitor{
    public:
        /**
         * @brief Constructor
         * @param inv Inventory reference
         */
        VisitHighCustomer(const Inventory& inv);
        ~VisitHighCustomer()=default;
        /**
         * @brief Visit ignorant cust
         * @param cust Customer to visit
         */
        void visitIgnorantCustomer(IgnorantCustomer& cust)override;
        /**
         * @brief Visit Average cust
         * @param cust Customer to visit
         */
        void visitAverageCustomer(AverageCustomer& cust)override;
        /**
         * @brief Visit greenFinger cust
         * @param cust Customer to visit
         */
        void visitGreenfingerCustomer(GreenFingerCustomer& cust)override;
};      

#endif