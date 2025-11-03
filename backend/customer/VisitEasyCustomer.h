/**
 * @file VisitEasyCustomer.h
 * @brief Visitor for creating plant recommendations for easy-maintenance customers
 */

#ifndef VISITEASYCUSTOMER_H
#define VISITEASYCUSTOMER_H

#include "CustomerVisitor.h"

/**
 * @class VisitEasyCustomer
 * @brief Visitor implementation for customers preferring easy-to-maintain plants
 * 
 * This visitor creates plant recommendations with a focus on easy-maintenance plants
 * while including some medium and hard difficulty plants based on customer type.
 * 
 * @see CustomerVisitor
 * @see IgnorantCustomerBuilder
 * @see AverageCustomerBuilder
 * @see GreenFingerCustomerBuilder
 */
class VisitEasyCustomer:public CustomerVisitor{
    public:
        /**
         * @brief Constructor
         * @param inv Inventory reference
         * @details Initializes with a copy of the salesfloor inventory
         */
        VisitEasyCustomer(const Inventory& inv);

        /**
         * @brief Default destructor
         */
        ~VisitEasyCustomer()=default;

        /**
         * @brief Create plant recommendation for ignorant customers
         * @param builder The customer builder being visited
         * @return Vector of recommended plants
         */
        vector<Plant*> visit(IgnorantCustomerBuilder& builder);

        /**
         * @brief Create plant recommendation for average customers
         * @param builder The customer builder being visited
         * @return Vector of recommended plants
         */
        vector<Plant*> visit(AverageCustomerBuilder& builder);

        /**
         * @brief Create plant recommendation for expert (green finger) customers
         * @param builder The customer builder being visited
         * @return Vector of recommended plants
         */
        vector<Plant*> visit(GreenFingerCustomerBuilder& builder);
};      

#endif