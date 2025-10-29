/**
 * @file VisitHighCustomer.h  
 * @brief Visitor for creating plant recommendations for customers preferring challenging plants
 */

#ifndef VISITMEDIUMCUSTOMER_H
#define VISITMEDIUMCUSTOMER_h

#include "CustomerVisitor.h"

/**
 * @class VisitHighCustomer
 * @brief Visitor implementation for customers preferring challenging plants
 * 
 * This visitor creates plant recommendations with a focus on medium and hard
 * difficulty plants while including some easy plants based on customer type.
 */
class VisitMediumCustomer:public CustomerVisitor{
    public:
        /**
         * @brief Constructor
         * @param inv Inventory reference
         */
        VisitMediumCustomer(const Inventory& inv);
        ~VisitMediumCustomer()=default;

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