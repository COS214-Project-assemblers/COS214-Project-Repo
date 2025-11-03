/**
 * @file VisitHighCustomer.h  
 * @brief Visitor for creating plant recommendations for customers preferring challenging plants
 */

#ifndef VISITMEDIUMCUSTOMER_H
#define VISITMEDIUMCUSTOMER_h

#include "CustomerVisitor.h"

/**
 * @class VisitMediumCustomer
 * @brief Visitor implementation for balanced plant recommendations
 * 
 * This visitor creates plant recommendations with a balanced mix of easy,
 * medium, and hard difficulty plants, adjusting proportions based on customer type.
 * 
 * @see CustomerVisitor
 * @see IgnorantCustomerBuilder
 * @see AverageCustomerBuilder
 * @see GreenFingerCustomerBuilder
 */
class VisitMediumCustomer:public CustomerVisitor{
    public:
        /**
         * @brief Constructor
         * @param inv Inventory reference
         * @details Initializes with a copy of the salesfloor inventory
         */
        VisitMediumCustomer(const Inventory& inv);
        
        /**
         * @brief Default destructor
         */
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