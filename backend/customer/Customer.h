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
 * @struct CustomerData
 * @brief Contains all customer attributes from JSON configuration
 */
struct CustomerData 
{
    string name;
    string introduce;
    string preferences;
    string recommendations;
    string accept;
    string reject;
    string acceptExit;
    string rejectExit;
    string type;  // "ignorant", "average", "greenfinger"
    
    CustomerData() = default;

    CustomerData(const map<string, string>& data, const string& customerType) 
    {
        name = data.at("name");
        introduce = data.at("introduce");
        preferences = data.at("preferences");
        recommendations = data.at("recommendations");
        accept = data.at("accept");
        reject = data.at("reject");
        acceptExit = data.at("acceptExit");
        rejectExit = data.at("rejectExit");
        type = customerType;
    }
};

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
        /**
         * @brief Displays the customer's introductory dialogue (Template Method Step 1).
         * Pure Virtual function to be implemented by derived classes.
         */
        virtual void introduce() = 0;

        /**
         * @brief Expresses the customer's plant preferences and living situation (Template Method Step 2).
         * Pure Virtual function to be implemented by derived classes.
         */
        virtual void expressPreferences() = 0;

        /**
         * @brief Asks the manager for plant recommendations (Template Method Step 3).
         * Pure Virtual function to be implemented by derived classes.
         */
        virtual void askForRecommendations() = 0;

        /**
         * @brief Reacts to the plant recommendations offered (Template Method Step 5).
         * Pure Virtual function to be implemented by derived classes.
         */
        virtual void reactToRecommendations() = 0;

        /**
         * @brief Displays the customer's exit message (Template Method Step 6).
         * Pure Virtual function to be implemented by derived classes.
         */
        virtual void thankAndExit() = 0;

    protected:
        /**
         * @brief Pointer to the plant chosen by the customer
         */
        const Plant* chosenPlant = nullptr;

        /**
         * @brief Flag indicating whether a plant was accepted
         */
        bool plantAccepted = false;

        /**
         * @brief List of plants offered by the visitor
         */
        vector<const Plant*> offeredPlants;

        CustomerData data;

    public:
        /**
         * @brief Default constructor
         */
        Customer();

        Customer(const CustomerData& customerData);

        /**
         * @brief Virtual destructor for proper polymorphic destruction.
         */
        virtual ~Customer();

        /**
         * @brief Accepts a visitor to handle plant recommendations (Template Method Step 4).
         * 
         * This method implements the Element side of the Visitor pattern, allowing the
         * CustomerVisitor to offer appropriate plants based on customer type.
         * 
         * @param v Reference to the CustomerVisitor that will offer plants.
         * Pure Virtual function to be implemented by derived classes.
         */
        virtual void accept(CustomerVisitor& v) = 0;

         /**
         * @brief Evaluates and selects from the offered plants.
         * 
         * This method presents the offered plants to the user and allows them to select one.
         * The customer will accept or reject based on whether the selection matches their preferences.
         * 
         * @param offers Vector of pointers to Plant objects available for selection.
         * @return Pointer to the chosen Plant, or nullptr if no suitable plant is selected.
         * Pure Virtual function to be implemented by derived classes.
         */
        virtual const Plant* considerOptions(const vector<const Plant*> offers) const = 0;

         /**
         * @brief Sets the plants offered by the visitor.
         * 
         * Called by CustomerVisitor implementations to provide the list of plants
         * that the customer will consider.
         * 
         * @param plants Vector of pointers to Plant objects being offered.
         */
        void setOfferedPlants(const vector<const Plant*>& plants);

        /**
         * @brief Template method defining the customer interaction workflow.
         * 
         * Implements the Template Method pattern by defining the fixed sequence of
         * customer interactions while delegating specific behaviors to primitive operations.
         * 
         * The interaction flow:
         * 1. Customer introduction
         * 2. Preference expression
         * 3. Request for recommendations
         * 4. Visitor offers plants (Visitor pattern)
         * 5. Customer reaction to offers
         * 6. Exit dialogue
         * 
         * @param v Reference to the CustomerVisitor that will handle plant recommendations.
         */
        void interact(CustomerVisitor& v);

        CustomerData getCustomerData();

        string getName();

        string getType();

        void setCustomerData(const CustomerData& customerData);
};

#endif