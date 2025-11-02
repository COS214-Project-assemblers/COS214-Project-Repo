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
 * as fallback. Inherits from Customer base class and implements the specific dialogue patterns and plant preferences.
 * 
 * @see Customer
 */

class AverageCustomer : public Customer
{
    public:
        /**
         * @brief Constructs a new AverageCustomer object.
         */
        AverageCustomer();

        /**
         * @brief Destroys the AverageCustomer object.
         * 
         * Cleans up any resources allocated by the AverageCustomer. Currently handles
         * basic cleanup through the base class destructor.
         */
        ~AverageCustomer();
};

#endif