/**
 * @file GreenFingerCustomer.h
 * @brief Concrete customer class representing expert plant enthusiasts.
 */

#ifndef GREENFINGERCUSTOMER_H
#define GREENFINGERCUSTOMER_H

#include "Customer.h"

/**
 * @class GreenFingerCustomer
 * @brief Represents an experienced plant enthusiast who seeks challenging specimens.
 * 
 * This customer type exclusively prefers plants with "Expert" care level and
 * will reject easy or moderate plants as too simple for their advanced skills.
 */

class GreenFingerCustomer : public Customer
{
    public:
        /**
         * @brief Constructs a new GreenFingerCustomer object.
         */
        GreenFingerCustomer();

        /**
         * @brief Destroys the GreenFingerCustomer object.
         */        
        ~GreenFingerCustomer();
};

#endif