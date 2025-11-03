/**
 * @file AverageCustomerBuilder.h
 * @brief Builder class for creating AverageCustomer objects with randomized dialogues.
 * @author Megan Norval
 */

#ifndef AVERAGECUSTOMERBUILDER_H
#define AVERAGECUSTOMERBUILDER_H

#include "AverageCustomer.h"
#include "CustomerBuilder.h"

/**
 * @class AverageCustomerBuilder
 * @brief Concrete builder for constructing AverageCustomer objects with random dialogue selection.
 * 
 * Implements the CustomerBuilder interface to create AverageCustomer instances with
 * randomly selected dialogues from the JSON configuration. Uses the Builder pattern
 * to separate customer construction from customer representation.
 * 
 * @see CustomerBuilder
 * @see AverageCustomer
 * @see Director
 */
class AverageCustomerBuilder : public CustomerBuilder
{
    private:
        /**
         * @brief Configuration source for customer dialogue options
         */
        GameConfiguraton* config;

        /**
         * @brief Random number generator for dialogue selection
         * 
         * Used to randomly select dialogue options from the available pools in the
         * JSON configuration file.
         */
        mt19937 rng;

    public:
        /**
         * @brief Constructs a new AverageCustomerBuilder object.
         * @param config Pointer to the game configuration containing customer data
         */
        AverageCustomerBuilder(GameConfiguraton* config);

        /**
         * @brief Destroys the AverageCustomerBuilder object.
         */
        ~AverageCustomerBuilder();

        /**
         * @brief Selects a random element from a string vector.
         * @param v Vector of strings to select from
         * @return Randomly selected string, or empty string if vector is empty
         */
        string getRandomElement(const vector<string>& v);

        // Builder interface implementation
        void buildName(string n);
        void buildIntroDialogue(string i);
        void buildPreferencesDialogue(string p);
        void buildRecommendationsDialogue(string r);
        void buildAcceptDialogue(string a);
        void buildRejectDialogue(string r);
        void buildAcceptExitDialogue(string a);
        void buildRejectExitDialogue(string r);
        void buildPlantOptions(const vector<Plant*>& plants);

        /**
         * @brief Accepts a visitor to provide plant recommendations
         * @param visitor Reference to the CustomerVisitor
         * @return Vector of Plant pointers recommended by the visitor
         * @details Implements the Element side of the Visitor pattern, allowing
         * different plant recommendation strategies to be applied during
         * customer construction.
         */
        vector<Plant*> accept(CustomerVisitor& visitor);
};

#endif