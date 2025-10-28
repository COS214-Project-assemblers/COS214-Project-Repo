/**
 * @file VisitEasyCustomer.h
 */
#ifndef VISITEASYCUSTOMER_H
#define VISITEASYCUSTOMER_H

#include "CustomerVisitor.h"

/**
 * @class VisitEasyCustomer
 * @brief EasyCustomer Visitor
 */
class VisitEasyCustomer:public CustomerVisitor{
    public:
        /**
         * @brief Constructor
         * @param inv Inventory reference
         */
        VisitEasyCustomer(const Inventory& inv);
        /**
         * @brief default constructor
         */
        ~VisitEasyCustomer()=default;
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