/**
 * @file AverageCustomer.h
 * @brief Concrete customer class representing moderately experienced plant buyers.
 * @author Megan Norval
 */

#ifndef AVERAGECUSTOMER_H
#define AVERAGECUSTOMER_H

#include "Customer.h"

/**
 * @class AverageCustomer
 * @brief Represents a customer with some plant experience who can handle moderate care requirements.
 * 
 * This customer type prefers plants with "Medium" care level.
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