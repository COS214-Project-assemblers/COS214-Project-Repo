/**
 * @file Customer.h
 * @brief Abstract base class for all customer types in the plant shop game.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "CustomerVisitor.h"
#include "Plant.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

/**
 * @class Customer
 * @brief Abstract base class defining the interface and shared behavior for all customer types.
 * 
 * This class serves as the base for all specific customer types (Ignorant, Average, GreenFinger).
 * It maintains customer dialogue, preferences, and plant offerings, and provides functionality
 * to serialize the customer data to JSON format for API communication.
 * 
 * The class provides the data structure that gets built by the Builder pattern.
 * 
 * @see IgnorantCustomer
 * @see AverageCustomer
 * @see GreenFingerCustomer
 * @see CustomerBuilder
 * @see CustomerVisitor
 */
class Customer
{
    protected:
        /**
         * @brief Complete JSON representation of the customer
         */
        string jsonStructure;
        
        /**
         * @brief Customer type identifier ("ignorant", "average", "greenfinger")
         */
        string type;

        /**
         * @brief Customer's randomly selected name
         */
        string name;

        /**
         * @brief Initial greeting dialogue
         */
        string introductionDialogue;

        /**
         * @brief Customer's plant preferences description
         */
        string preferencesDialogue;

        /**
         * @brief Request for plant recommendations
         */
        string recommendationsDialogue;

        /**
         * @brief Dialogue when accepting a plant
         */
        string acceptDialogue;

        /**
         * @brief Dialogue when rejecting a plant
         */
        string rejectDialogue;

        /**
         * @brief Exit dialogue after accepting
         */
        string acceptExitDialogue;

        /**
         * @brief Exit dialogue after rejecting
         */
        string rejectExitDialogue;

        /**
         * @brief JSON string of plants offered to the customer
         */
        string offeredPlants;

    public:
        /**
         * @brief Default constructor
         * 
         * Initializes a new Customer instance with empty dialogue fields.
         * Derived classes should set the specific customer type.
         */
        Customer();

        /**
         * @brief Virtual destructor for proper polymorphic destruction.
         */
        virtual ~Customer();

        /**
         * @brief Getter for the jsonStructure member variable 
         * @return The jsonStructure as a string for the API endpoint
         * 
         * Constructs and returns a complete JSON representation of the customer
         * including all dialogues and offered plants.
         */
        string getStructure();

        /**
         * @brief Getter for the type of Customer
         * @return Customer type as string
         */
        string getType();

        /**
         * @brief Escapes special JSON characters in a string
         * @param input The string to escape
         * @return Escaped string safe for JSON inclusion
         * 
         * Handles escaping of quotes, backslashes, and control characters
         * to ensure valid JSON output.
         */
        string escapeJsonString(const string& input);

        // Setters for customer properties
        void setName(string n);
        void setIntroductionDialogue(string i);
        void setPreferencesDialogue(string p);
        void setRecommendationsDialogue(string r);
        void setAcceptDialogue(string a);
        void setRejectDialogue(string r);
        void setAcceptExitDialogue(string a);
        void setRejectExitDialogue(string r);

        /**
         * @brief Sets the plants offered to the customer
         * @param plants Vector of Plant pointers to offer
         * 
         * Converts the plant vector to JSON format and stores it as a string
         * for inclusion in the customer's JSON structure.
         */
        void setOfferedPlants(const vector<Plant*>& plants);
};

#endif