/**
 * @file VisitHighCustomer.h  
 * @brief Visitor for creating plant recommendations for customers preferring challenging plants
 */

#ifndef VISITHIGHCUSTOMER_H
#define VISITHIGHCUSTOMER_h

#include "CustomerVisitor.h"

/**
 * @class VisitHighCustomer
 * @brief Visitor implementation for customers preferring challenging plants
 * 
 * This visitor creates plant recommendations with a focus on medium and hard
 * difficulty plants while including some easy plants based on customer type.
 */

class VisitHighCustomer:public CustomerVisitor{
    public:
        /**
         * @brief Constructor
         * @param inv Inventory reference
         */
        VisitHighCustomer(const Inventory& inv);
        ~VisitHighCustomer()=default;

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