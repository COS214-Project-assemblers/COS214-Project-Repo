/**
 * @file IgnorantCustomerBuilder.h
 * @brief Builder class for creating IgnorantCustomer objects with randomized dialogues.
 * @author Megan Norval
 */

#ifndef IGNORANTCUSTOMERBUILDER_H
#define IGNORANTCUSTOMERBUILDER_H

#include "CustomerBuilder.h"
#include "IgnorantCustomer.h"

/**
 * @class IgnorantCustomerBuilder
 * @brief Concrete builder for constructing IgnorantCustomer objects with random dialogue selection.
 * 
 * Implements the CustomerBuilder interface to create IgnorantCustomer instances with
 * randomly selected dialogues from the JSON configuration. Uses the Builder pattern
 * to separate customer construction from customer representation.
 * 
 * @see CustomerBuilder
 * @see IgnorantCustomer
 * @see Director
 */
class IgnorantCustomerBuilder: public CustomerBuilder
{
    private:
        /**
         * @brief Configuration source for customer dialogue options
         */
        GameConfiguraton* config;

        /**
         * @brief Random number generator for dialogue selection
         * @details Used to randomly select dialogue options from the available pools in the
         * JSON configuration file for ignorant customers.
         */
        mt19937 rng;

    public:
        /**
         * @brief Constructs a new IgnorantCustomerBuilder object.
         * @param config Pointer to the game configuration containing customer data
         * @details Initializes the random number generator with current time seed
         */
        IgnorantCustomerBuilder(GameConfiguraton* config);

        /**
         * @brief Destroys the IgnorantCustomerBuilder object.
         * @details Cleans up resources. Note: Does not own the config pointer.
         */
        ~IgnorantCustomerBuilder();

        /**
         * @brief Selects a random element from a string vector.
         * @param v Vector of strings to select from
         * @return Randomly selected string, or empty string if vector is empty
         * @details Uses the internal RNG to select a random index
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
         * @brief Accepts a visitor to provide plant recommendations.
         * @param visitor Reference to the CustomerVisitor that will recommend plants
         * @return Vector of Plant pointers recommended by the visitor
         * @details Implements the Visitor pattern to allow different plant recommendation
         * strategies to be applied to the ignorant customer being built.
         */
        vector<Plant*> accept(CustomerVisitor& visitor);
};

#endif