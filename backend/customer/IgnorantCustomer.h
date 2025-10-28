/**
 * @file IgnorantCustomer.h
 * @brief Concrete customer class representing inexperienced plant buyers.
 */

#ifndef IGNORANTCUSTOMER_H
#define IGNORANTCUSTOMER_H

#include "Customer.h"

/**
 * @class IgnorantCustomer
 * @brief Represents a customer with minimal plant knowledge who needs easy-care plants.
 * 
 * This customer type prefers plants that are hard to kill and require minimal maintenance.
 * They will only accept plants with "Easy" care level and will reject complex plants.
 */
class IgnorantCustomer : public Customer
{
    private:
        string type = "ignorant";

    public:
        /**
         * @brief Constructs a new IgnorantCustomer object.
         */
        IgnorantCustomer();

        /**
         * @brief Destroys the IgnorantCustomer object.
         */
        ~IgnorantCustomer();
};

#endif