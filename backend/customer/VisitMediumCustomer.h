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
        vector<Plant*> visit(IgnorantCustomerBuilder& builder);
        /**
         * @brief Visit Average cust
         * @param cust Customer to visit
         */
        vector<Plant*> visit(AverageCustomerBuilder& builder);
        /**
         * @brief Visit GreenFinger cust
         * @param cust Customer to visit
         */
        vector<Plant*> visit(GreenFingerCustomerBuilder& builder);
};      

#endif