/**
 * @file CustomerBuilder.h
 * @brief Abstract builder interface for creating Customer objects.
 */

#ifndef CUSTOMERBUILDER_H
#define CUSTOMERBUILDER_H

#include "Customer.h"
#include "CustomerVisitor.h"
#include "JSONGameConfiguration.h"

#include <random>
#include <chrono>

/**
 * @class CustomerBuilder
 * @brief Abstract base class for building Customer objects step by step.
 * 
 * Defines the interface for constructing Customer objects through a series of
 * build steps. Follows the Builder pattern to separate the construction of
 * complex Customer objects from their representation.
 * 
 * Concrete builders implement this interface to create specific customer types
 * with randomly selected dialogues from configuration and visitor-provided plants.
 * 
 * @see AverageCustomerBuilder
 * @see IgnorantCustomerBuilder
 * @see GreenFingerCustomerBuilder
 * @see Director
 */
class CustomerBuilder
{
    protected:
        /**
         * @brief The customer object being built
         */
        Customer* customer;

    public:
        /**
         * @brief Default constructor
         * 
         * Initializes the customer pointer to nullptr. Concrete builders should
         * create the appropriate customer type in their constructors.
         */
        CustomerBuilder();

        /**
         * @brief Virtual destructor
         * 
         * Ensures proper cleanup of derived builder objects. Note: The customer
         * object is typically managed by the Game class, not the builder.
         */
        virtual ~CustomerBuilder();

        // Builder interface methods
        virtual void buildName(string n) = 0;
        virtual void buildIntroDialogue(string i) = 0;
        virtual void buildPreferencesDialogue(string p) = 0;
        virtual void buildRecommendationsDialogue(string r) = 0;
        virtual void buildAcceptDialogue(string a) = 0;
        virtual void buildRejectDialogue(string r) = 0;
        virtual void buildAcceptExitDialogue(string a) = 0;
        virtual void buildRejectExitDialogue(string r) = 0;
        
        virtual void buildPlantOptions(const vector<Plant*>& plants) = 0;

        /**
         * @brief Returns the built customer object
         * @return Pointer to the constructed Customer object
         * 
         * Transfers ownership of the customer to the caller.
         */
        Customer* getCustomer();

        /**
         * @brief Accepts a visitor to provide plant recommendations
         * @param visitor Reference to the CustomerVisitor
         * @return Vector of Plant pointers recommended by the visitor
         * 
         * Implements the Element side of the Visitor pattern, allowing
         * different plant recommendation strategies to be applied during
         * customer construction.
         */
        virtual vector<Plant*> accept(CustomerVisitor& visitor) = 0;
};

#endif