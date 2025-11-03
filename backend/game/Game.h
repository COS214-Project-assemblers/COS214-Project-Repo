/**
 * @file Game.h
 * @brief Header file for Game class - Main game facade
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
#include "GreenSock.h"

using namespace std;

class Greenhouse;
class PlantCreator;

/**
 * @class Game
 * @brief The main game class representing the internal API of the system
 * @details Models the Facade design pattern to provide a simplified interface
 * to the complex subsystem of game components including greenhouse, customers,
 * inventory, and financial systems.
 */
class Game {
    private:
        /**
         * @brief attribute that maintains reference to the game's greenhouse object
         */
        Greenhouse* greenhouse = nullptr;

        /**
         * @brief Map of plant creators (factories) for different plant categories
         */
        map<string, PlantCreator*> factories;

        /**
         * @brief Game configuration provider
         */
        GameConfiguraton* config = nullptr;

        /**
         * @brief Logger for game events
         */
        Logger* logger = nullptr;

        /** 
         * @brief Maps plant varieties to their categories for easy lookup
         * @details Enables Factory Method pattern to find correct creator for plant types
         */
        map<string, string> varietyToCategory;

        /**
         * @brief Collection of active customers in the game
         */
        vector<Customer*> customers;

        /**
         * @brief Reference to the manager object handling game operations
         */
        Manager* manager = nullptr;

        /**
         * @brief WebSocket connection for real-time communication
         */
        GreenSock* socket = nullptr;

    public:

        /**
         * @brief Constructor - initializes game with configuration
         * @param configPath Path to game configuration file
         */
        Game(string configPath);

        /**
         * @brief Setter for greenhouse attribute
         * @param greenhouse Pointer to Greenhouse instance
         */
        void setGreenhouse(Greenhouse* greenhouse);

        /**
         * @brief Getter for greenhouse
         * @return Pointer to Greenhouse instance
         */
        Greenhouse* getGreenhouse();

        /**
         * @brief Setter for plant factories
         * @param factories Map of plant category to PlantCreator factories
         */
        void setFactories(map<string, PlantCreator*> factories);

        /**
         * @brief Getter for factories
         * @return Map of plant factories
         */
        map<string, PlantCreator*> getFactories();

        /**
         * @brief Operations for creating a new game instance
         * @details Creates greenhouse, initializes factories, and sets up game state
         */
        void createNewGame();

        /**
         * @brief Buys plants and adds them to the Greenhouse
         * @param plant The specific plant variety to buy (e.g., "cactus", "rose", "lemon")
         * @param num The number of plants to buy
         * @throws runtime_error if plant variety not found or greenhouse not initialized
         */
        void buyPlants(string plant, int num);

        /**
         * @brief Destructor - cleans up game resources
         * @details Frees greenhouse, plant creators memory, and other resources
         */
        ~Game();

        /**
         * @brief Helper method to get category for a plant variety
         * @param variety The plant variety to look up
         * @return The category name
         * @throws runtime_error if variety not found in configuration
         */
        string getCategoryForVariety(string variety);
        
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

        /**
         * @brief Get all customers as a JSON array string
         * @return JSON string containing all customers
         */
        vector<PlantStruct*> getAvailablePlantVarieties();

        /**
         * @brief Exits game gracefully
         * @details Logs exit operation. Memory cleanup handled by destructor
         */
        void exitGame();

        /**
         * @brief Setter for manager
         * @param m Pointer to Manager instance
         */
        void setManager(Manager* m);

        /**
         * @brief Getter for manager
         * @return Pointer to Manager instance
         */
        Manager* getManager();

        /**
         * @brief Get current game balance
         * @return Current balance as float
         */
        float getGameBalance();

        /**
         * @brief Setter for WebSocket connection
         * @param socket Pointer to GreenSock instance
         */
        void setSocket(GreenSock* socket);

        /**
         * @brief Get greenhouse plants as vector
         * @return Vector of Plant pointers in greenhouse
         */
        vector<Plant*> getGreenhousePlants();

        /**
         * @brief Get greenhouse plants as JSON string
         * @return JSON string containing greenhouse plants data
         */
        string getGreenhousePlantsAsJson();

        /**
         * @brief Perform care action on a specific plant
         * @param id Plant identifier
         */
        void careForPlant(string id);

        /**
         * @brief Make a sale of a plant
         * @param id Plant identifier to sell
         */
        void makeSale(string id);

        /**
         * @brief Clear all customers from the game
         */
        void clearCustomers();
};

#endif