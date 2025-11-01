/**
 * @file Game.h
 * @brief Header file for Game class
 * @author Gerard Jordaan
 */
#ifndef GAME_HDR
#define GAME_HDR

#include <map>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include "Logger.h"
#include <vector>

#include "GameConfiguration.h"
#include "Customer.h"
#include "CustomerBuilder.h"
#include "Manager.h"

using namespace std;

// For now, and to be safe, I am forward declaring classes instead of including
// their header files to avoid circular dependencies, i.e. the Greenhouse class 
// can include Game.h in its header file and then we are fu..screwed (just checking
// if you are actually reading comments)
class Greenhouse;
class PlantCreator;

/**
 * @class Game
 * @brief The Game class represents the internal API of the system.
 *  It is modelled in terms of the Facade design pattern.
 */
class Game {
    private:
        /**
         * @brief attribute that maintains reference to the game's greenhouse object
         */
        Greenhouse* greenhouse = nullptr;
        /**
         * @brief maintains reference to plant creators for the game
         */
        map<string, PlantCreator*> factories;

        GameConfiguraton* config = nullptr;

        /**
         * @brief Used to log all game events
         */
        Logger* logger = nullptr;
        /** 
         * @brief Maps plant varieties to their categories for easy lookup during plant purchases
         * This enables the Factory Method pattern to find the correct creator for each plant type
         */
        map<string, string> varietyToCategory;

        vector<Customer*> customers;
        Manager* manager = nullptr;///<Maintains ref to the manager object
    public:
        /**
         * @brief Game initialization tasks that are not creating/loading game.
         *  Wil problably init DB connection etc here
         */
        Game(string configPath);
        /**
         * @brief Setter for greenhouse attribute
         * @param[in] greenhouse Greenhouse reference
         */
        void setGreenhouse(Greenhouse* greenhouse);
        /**
         * @brief Getter for testing purposes
         */
        Greenhouse* getGreenhouse();
        /**
         * @brief Setter for factories
         * @param[in] factories Vector of PlantCreator object references, these are the "factories"
         */
        void setFactories(map<string, PlantCreator*> factories);
        /**
         * @brief Getter for testing purposes
         */
        map<string, PlantCreator*> getFactories();

        /**
         * @brief Operations associated with creating a new game, i.e. creating greenhouse and factories
         */
        void createNewGame();

        /**
         * @brief This is used by the user to be able to buy plants to add to the Greenhouse.
         *  Uses Factory Method pattern to find correct plant creator and Prototype pattern to clone plants.
         * @param plant The specific plant variety to buy (e.g., "cactus", "rose", "lemon")
         * @param num The number of plants to buy
         * @throws runtime_error if plant variety not found or greenhouse not initialized
         */
        void buyPlants(string plant, int num);
        /**
         * @brief loads greenhouse and factories from DB
         */
        void loadExistingGame();
        /**
         * Saves state of greenhouse and factories in DB
         */
        void saveGame();
        /**
         * @brief Frees greenhouse, plant creators memory. Closes DB connection.
         */
        ~Game();

        /**
         * @brief Helper method to get category for a plant variety
         * @param variety The plant variety to look up
         * @return The category name
         * @throws runtime_error if variety not found in configuration
         */
        string getCategoryForVariety(string variety);
        
        // /**
        //  * @brief Get all available plant varieties from configuration
        //  * @return Map of categories to plant varieties
        //  */
        // map<string, vector<string>> getAvailablePlantVarieties();

        /**
         * @brief Getter for customers vector
         * @return Vector of Customer pointers
         */
        vector<Customer*> getCustomers();

        /**
         * @brief Creates and adds customers to the game
         * @param type The type of customer to add ("ignorant", "average", "greenfinger")
         * @param num The number of customers to add
         * @throws runtime_error if customer creation fails
         */
        void createCustomers(string type, int num);

        /**
         * @brief Get available customer types from configuration
         * @return Map of customer types to their definitions
         */
        map<string, map<string, vector<string>>> getAvailableCustomerTypes();

        /**
         * @brief Get all customers as a JSON array string
         * @return JSON string containing all customers
         */
        string getCustomersAsJson();

        
        vector<PlantStruct*> getAvailablePlantVarieties();

        /**
         * @brief Exits game gracefully, atp it is just logging that the user opted to end the game,
         * but if the game were to scale this would obviously contain crucial shutdown steps. No mem is
         * freed since the destructor of the Game will be called when it is deleted in mem
         */
        void exitGame();
        void setManager(Manager* m);

        float getGameBalance();

        vector<Plant*> getGreenhousePlants();
        string getGreenhousePlantsAsJson();
};

#endif // GAME_HDR