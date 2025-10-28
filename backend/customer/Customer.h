/**
 * @file Customer.h
 */
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

#include "CustomerVisitor.h"
#include "Plant.h"

/**
 * @class Customer
 * @brief Abstract base class defining the interface and shared behavior for all customer types.
 * 
 * The Customer class implements the Template Method pattern, defining the skeleton of the customer
 * interaction algorithm while allowing subclasses to override specific steps. It also serves as
 * an Element in the Visitor pattern for plant recommendation handling.
 * 
 * @note This class follows the Template Method design pattern for the interaction flow
 * and participates in the Visitor pattern for plant recommendations.
 * 
 * @see IgnorantCustomer
 * @see AverageCustomer
 * @see GreenFingerCustomer
 * @see CustomerVisitor
 */

class Customer
{
    private:
       string jsonStructure;

    protected:
        /**
         * @brief List of plants offered by the visitor
         */
        // vector<const Plant*> offeredPlants; // needs to be converted to a json structure so that it can be added to jsonString

    public:
        /**
         * @brief Default constructor
         */
        Customer();

        /**
         * @brief Virtual destructor for proper polymorphic destruction.
         */
        virtual ~Customer();

        /**
         * @brief Getter for the jsonStructure member variable 
         * @returns The jsonStructure as a string for the API endpoint
         */
        string getStructure();

        /////////////////////////////////////
        // The following functions might need to be moved to the builders
        /////////////////////////////////////


        /**
         * @brief Accepts a visitor to handle plant recommendations
         * 
         * This method implements the Element side of the Visitor pattern, allowing the
         * CustomerVisitor to offer appropriate plants based on customer type.
         * 
         * @param v Reference to the CustomerVisitor that will offer plants.
         * Pure Virtual function to be implemented by derived classes.
         */
        // virtual void accept(CustomerVisitor& v) = 0;

         /**
         * @brief Sets the plants offered by the visitor.
         * 
         * Called by CustomerVisitor implementations to provide the list of plants
         * that the customer will consider.
         * 
         * @param plants Vector of pointers to Plant objects being offered.
         */
        // void setOfferedPlants(const vector<const Plant*>& plants); // this will actually convert the vector of plants into a json structured string for the jsonStructure member variable
};

#endif