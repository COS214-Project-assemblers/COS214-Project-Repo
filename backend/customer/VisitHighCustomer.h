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
        vector<Plant*> visit(IgnorantCustomerBuilder& builder);
        /**
         * @brief Visit Average cust
         * @param cust Customer to visit
         */
        vector<Plant*> visit(AverageCustomerBuilder& builder);
        /**
         * @brief Visit greenFinger cust
         * @param cust Customer to visit
         */
        vector<Plant*> visit(GreenFingerCustomerBuilder& builder);
};      

#endif