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
 * @brief Abstract base class defining interface and shared behavior of Customer
 * 
 * The Customer class defines the interation methods with the sales floor that is used by all the customer types, 
 * such as displaying dialogue, and choosing to make purchases.
 * 
 * @see IgnorantCustomer
 * @see AverageCustomer
 * @see GreenFingerCustomer
 */

class Customer
{
    private:
        /**
         * @brief primitiveOperation1()
         * Displays the customer's introductory dialog that is unique to each Customer
         */
        virtual void introduce() = 0;

        /**
         * @brief primitiveOperation2()
         * Displays the customer's preference in plants and what their living situation is
         */
        virtual void expressPreferences() = 0;

        /**
         * @brief primitiveOperation3()
         * Displays the customer's question to ask for plant recommendations
         */
        virtual void askForRecommendations() = 0;

        /**
         * @brief primitiveOperation5()
         * Displays the customer's reactions to the plant recommendation
         * Currently the customer only accepts the plant, but this is probably where the logic of the 
         * correct / wrong chosen plant recommendation will be implemented
         */
        virtual void reactToRecommendations() = 0;

        /**
         * @brief primitiveOperation6()
         * Displays the exit message for each customer
         */
        virtual void thankAndExit() = 0;

    protected:
        const Plant* chosenPlant = nullptr;
        bool plantAccepted = false;
        std::vector<const Plant*> offeredPlants;

        std::string generateRejectionDialogue();

    public:
        /**
         * @brief Default constructor
         */
        Customer();

        /**
         * @brief virtual deconstructor
         */
        virtual ~Customer();

        /**
         * @brief primitiveOperation4()
         * This is where the visitor comes in and gives the customer plant options based on what type of customer they are
         */
        virtual void accept(CustomerVisitor& v) = 0;

        /**
         * @brief Allows for customer to evaluate and consider offered plants.
         * @param offers A vector of pointers to Plant objects of the plants on offer.
         * @return A pointer to the chosen Plant or NULL if none are chosen.
         */
        virtual const Plant* considerOptions(const vector<const Plant*> offers) const = 0;

        /**
         * @brief Set the plants offered by the visitor
         */
        void setOfferedPlants(const vector<const Plant*>& plants);

        /**
         * @brief Template method
         * This function initiates the customer interaction flow (sequence of primitive operations)
         * @param [in] v Visitor object that is needed for the accept() method
         */
        void interact(CustomerVisitor& v);
};

#endif