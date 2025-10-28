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
         * @brief Visit IgnorantCustomerBuilder
         * @param builder Builder to visit
         */
        vector<Plant*> visit(IgnorantCustomerBuilder& builder);
        /**
         * @brief Visit AverageCustomerBuilder
         * @param builder Builder to visit
         */
        vector<Plant*> visit(AverageCustomerBuilder& builder);
        /**
         * @brief Visit GreenFingerCustomerBuilder
         * @param builder Builder to visit
         */
        vector<Plant*> visit(GreenFingerCustomerBuilder& builder);
};      

#endif