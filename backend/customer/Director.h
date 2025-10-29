/**
 * @file Director.h
 * @brief Director class for coordinating customer construction using builders and visitors.
 */

#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "CustomerBuilder.h"
#include "CustomerVisitor.h"

/**
 * @class Director
 * @brief Coordinates the construction of Customer objects using builders and visitors.
 * 
 * The Director class implements the Director role in the Builder pattern, orchestrating
 * the step-by-step construction of Customer objects. It works with CustomerBuilder
 * implementations to build customer dialogues and uses CustomerVisitor implementations
 * to provide plant recommendations.
 * 
 * This class separates the construction logic from the builder implementations,
 * allowing different construction sequences or strategies to be implemented.
 * 
 * @see CustomerBuilder
 * @see CustomerVisitor
 */
class Director
{
    private:
        /**
         * @brief Current builder being used for customer construction
         */
        CustomerBuilder* builder;

    public:
        /**
         * @brief Default constructor
         * 
         * Initializes the director with no active builder.
         */
        Director();

        /**
         * @brief Destructor
         * 
         * Cleans up director resources. Note: The builder is managed externally
         * and should be deleted by the caller.
         */
        ~Director();

        /**
         * @brief Sets the current builder for customer construction
         * @param b Pointer to the CustomerBuilder to use
         */
        void setBuilder(CustomerBuilder* b);

        /**
         * @brief Constructs a complete customer using the current builder and visitor
         * @param v Reference to the CustomerVisitor for plant recommendations
         * @return Pointer to the fully constructed Customer object
         * 
         * Executes the complete customer construction process:
         * 1. Builds all dialogue parts using the builder
         * 2. Gets plant recommendations from the visitor
         * 3. Sets the plant options on the customer
         * 
         * @throws std::runtime_error if no builder is set
         */
        Customer* construct(CustomerVisitor& v);

        /**
         * @brief Returns the JSON structure of the currently built customer
         * @return JSON string representation of the customer
         * 
         * @throws std::runtime_error if no builder is set or no customer is built
         */
        string getCustomerJsonStructure();
};

#endif