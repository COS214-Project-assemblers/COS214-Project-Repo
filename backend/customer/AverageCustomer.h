/**
 * @file AverageCustomer.h
 * @brief Concrete customer class representing moderately experienced plant buyers.
 */

#ifndef AVERAGECUSTOMER_H
#define AVERAGECUSTOMER_H

#include "Customer.h"

/**
 * @class AverageCustomer
 * @brief Represents a customer with some plant experience who can handle moderate care requirements.
 * 
 * This customer type prefers plants with "Moderate" care level but will accept "Easy" plants
 * as fallback.
 */

class AverageCustomer : public Customer
{
    private:
       string type = "average";

    public:
        /**
         * @brief Constructs a new AverageCustomer object.
         */
        AverageCustomer();

        /**
         * @brief Destroys the AverageCustomer object.
         */
        ~AverageCustomer();
};

#endif