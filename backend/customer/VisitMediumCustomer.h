#ifndef VISITMEDIUMCUSTOMER_H
#define VISITMEDIUMCUSTOMER_h

#include "CustomerVisitor.h"

class VisitMediumCustomer:public CustomerVisitor{
    public:
        /**
         * @brief Constructor
         * @param inv Inventory reference
         */
        VisitMediumCustomer(const Inventory& inv);
        ~VisitMediumCustomer()=default;
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
         * @brief Visit GreenFinger cust
         * @param cust Customer to visit
         */
        void visitGreenfingerCustomer(GreenFingerCustomer& cust)override;
};      

#endif