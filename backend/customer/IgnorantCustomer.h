/**
 * @file IgnorantCustomer.h
 * @brief Concrete customer class representing inexperienced plant buyers.
 * @author Megan Norval
 */

#ifndef IGNORANTCUSTOMER_H
#define IGNORANTCUSTOMER_H

#include "Customer.h"

/**
 * @class IgnorantCustomer
 * @brief Represents a customer with minimal plant knowledge who needs easy-care plants.
 * 
 * This customer type prefers plants that are hard to kill and require minimal maintenance.
 * They have simple dialogue patterns reflecting their lack of plant knowledge and seek
 * plants that can survive with minimal attention.
 * 
 * Inherits from Customer base class and implements the ignorant customer type
 * with specific dialogue patterns and plant preferences.
 * 
 * @see Customer
 */
class IgnorantCustomer : public Customer
{
    public:
        /**
         * @brief Constructs a new IgnorantCustomer object.
         * @details Initializes the customer type as "ignorant" and sets up base customer structure.
         */
        IgnorantCustomer();

        /**
         * @brief Destroys the IgnorantCustomer object.
         * @details Cleans up resources through base class destructor.
         */
        ~IgnorantCustomer();
};

#endif