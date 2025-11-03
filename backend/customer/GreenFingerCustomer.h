/**
 * @file GreenFingerCustomer.h
 * @brief Concrete customer class representing expert plant enthusiasts.
 * @author Megan Norval
 */

#ifndef GREENFINGERCUSTOMER_H
#define GREENFINGERCUSTOMER_H

#include "Customer.h"

/**
 * @class GreenFingerCustomer
 * @brief Represents an experienced plant enthusiast who seeks challenging specimens.
 * 
 * This customer type prefers plants with higher difficulty levels and has sophisticated
 * dialogue patterns reflecting their expertise. They are knowledgeable about plant care
 * and seek specimens that match their advanced gardening skills.
 * 
 * Inherits from Customer base class and implements specific dialogue patterns and plant preferences.
 * 
 * @see Customer
 */
class GreenFingerCustomer : public Customer
{
    public:
        /**
         * @brief Constructs a new GreenFingerCustomer object.
         * @details Initializes the customer type as "greenfinger" and sets up base customer structure.
         */
        GreenFingerCustomer();

        /**
         * @brief Destroys the GreenFingerCustomer object.
         * @details Cleans up resources through base class destructor.
         */        
        ~GreenFingerCustomer();
};

#endif