#include "Game.h"
#include "Greenhouse.h"
#include "JSONGameConfiguration.h"
#include "BasicLogger.h"
#include "LogDecorator.h"
#include "CoutAndLog.h"

#include "FlowerCreator.h"
#include "SucculentCreator.h"
#include "TreeCreator.h"

#include "AverageCustomerBuilder.h"
#include "IgnorantCustomerBuilder.h"
#include "GreenFingerCustomerBuilder.h"
#include "Director.h"
#include "VisitEasyCustomer.h"
#include "VisitMediumCustomer.h"
#include "VisitHighCustomer.h"
#include "Inventory.h"

Game::Game(string configPath)
{
    CoutAndLog* logDec = new CoutAndLog();
    logDec->setBaseLogger(new BasicLogger());
    logger = logDec;

    try
    {
        logger->newLog("Attempting to load JSON game configuration " + configPath);
        config = new JSONGameConfiguration(configPath);

        map<string, vector<int>> plantCosts;
        vector<PlantStruct*> plants = config->getPlantVarieties();        for (PlantStruct* p : plants)
        {
            string variety = p->variety;
            varietyToCategory[variety] = p->category;
            string mapMessage = "✓ Mapped variety '" + variety + "' to category '" + p->category + "'";
            logger->newLog(mapMessage);
            vector<int> costs = {p->costPrice, p->salePrice};
            plantCosts[variety] = costs;
            string costMessage =  "✓ Saved cost price of " + variety + ": " + to_string(costs[0]);
            logger->newLog(costMessage);
            costMessage = "✓ Saved sale price of " + variety + ": " + to_string(costs[1]);
            logger->newLog(costMessage);
            delete p;
        }

        Plant::setPlantCosts(plantCosts);
        Plant::setLogger(logger);
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
        logger->newLog(string(e.what()) + "\nEXITING WITH EXIT CODE 1");
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    catch (const out_of_range &e)
    {
        cout << e.what() << endl;
        logger->newLog(string(e.what()) + "\nEXITING WITH EXIT CODE 1");
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    catch (...)
    {
        cout << "Failed to init config for unknown reason" << endl;
        logger->newLog("Failed to init config for unknown reason \nEXITING WITH EXIT CODE 1");
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    }
}

void Game::setGreenhouse(Greenhouse *greenhouse)
{
    this->greenhouse = greenhouse;
}

Greenhouse *Game::getGreenhouse()
{
    return greenhouse;
}

void Game::setFactories(map<string, PlantCreator *> factories)
{
    this->factories = factories;
}

map<string, PlantCreator *> Game::getFactories()
{
    return factories;
}

void createFactoriesHelper(string category, string variant, map<string, PlantCreator *>& factories, Logger* logger)
{
        // Not optimal, but at least centralized
        PlantCreator* newPlantCreator;
        if (category == "succulents") {
            newPlantCreator = new SucculentCreator();
        } else if (category == "flowers") {
            newPlantCreator = new FlowerCreator();
        } else if (category == "trees") {
            newPlantCreator = new TreeCreator();
        } else {
            cout << "Category " + category + " does not exist" << endl;
            return;
        }

        newPlantCreator->makePlant(variant);
        string message = "+ Made " + category + " factory for variety [" + variant + "]";
        logger->newLog(message);
        factories[variant] = newPlantCreator;
    
}

void Game::createNewGame()
{
    // try
    try
    {
        
        // Create new factories
        vector<PlantStruct*> plants;
        map<string, vector<string>> varieties;
        map<string, PlantCreator *> factories;

        plants = config->getPlantVarieties();

        for (PlantStruct* plant : plants) {
            createFactoriesHelper(plant->category, plant->variety, factories, logger);
            delete plant;
        }
        setFactories(factories);

        logger->newLog("+ Created factories");
    }
    catch (...)
    {                                                                         // More specific error handling required
        throw runtime_error("Failed to create factories for unknown reason"); // Reason is unknown since using catch(...)
    }

    try
    {
        setGreenhouse(new Greenhouse());
        logger->newLog("+ Created greenhouse");
    }
    catch (...)
    {
        throw runtime_error("Failed to create greenhouse for unknown reason");
    }

    manager = new Manager();
}

void Game::buyPlants(string plant, int num) 
{
    if (num <= 0) 
    {
        throw runtime_error("Number of plants must be positive, got: " + to_string(num));
    }
    
    if (greenhouse == nullptr) 
    {
        throw runtime_error("Greenhouse not initialized. Please create a new game first.");
    }
    
    if (factories.empty()) 
    {
        throw runtime_error("No plant factories available. Please create a new game first.");
    }

    if(manager == nullptr)
    {
        throw runtime_error("No manager available. Please create a new game first.");
    }

    auto factoryIt = factories.find(plant);

    if (factoryIt == factories.end()) 
    {
        string availablePlants = "Available plants: ";
        for (const auto& [variety, creator] : factories) 
        {
            availablePlants += variety + " ";
        }

        throw runtime_error("Plant variety '" + plant + "' not found. " + availablePlants);
    }
    
    PlantCreator* factory = factoryIt->second;
    
    for (int i = 0; i < num; i++) 
    {
        Plant* clonedPlant = factory->clonePlant();

        if (clonedPlant != nullptr) 
        {
            manager->recordRestock(*clonedPlant);
            greenhouse->addPlant(clonedPlant);
        } 
        else 
        {
            throw runtime_error("Failed to clone plant: " + plant);
        }
    }
}

void Game::loadExistingGame() {}

void Game::saveGame() {}

Game::~Game()
{
    if (logger != nullptr) {
        delete logger;
    }
    for (auto it = factories.begin(); it != factories.end(); ++it)
    {
        delete it->second;
    }

    for (auto customer : customers)
    {
        if(customer)
        {
            delete customer;
        }
    }

    if (config != nullptr)
    {
        delete config;
    }

    if (greenhouse != nullptr)
    {
        delete greenhouse;
    }

    if(manager)
    {
        delete manager;
    }
}

string Game::getCategoryForVariety(string variety) 
{
    auto it = varietyToCategory.find(variety);

    if (it == varietyToCategory.end()) 
    {
        throw runtime_error("Plant variety '" + variety + "' not found in configuration");
    }

    return it->second;
}

vector<PlantStruct*> Game::getAvailablePlantVarieties() 
{
    return config->getPlantVarieties();
}

void Game::createCustomers(string type, int num)
{
    if (num <= 0) 
    {
        throw runtime_error("Number of customers must be positive, got: " + to_string(num));
    }
    
    if (greenhouse == nullptr) 
    {
        throw runtime_error("Greenhouse not initialized. Please create a new game first.");
    }

    if (manager == nullptr) 
    {
        throw runtime_error("Manager is null");
    }

    // Validate customer type exists in configuration
    auto availableCustomerTypes = getAvailableCustomerTypes();
    if (availableCustomerTypes.find(type) == availableCustomerTypes.end()) 
    {
        string availableTypes = "Available customer types: ";

        for (const auto& [customerType, data] : availableCustomerTypes) 
        {
            availableTypes += customerType + " ";
        }

        throw runtime_error("Customer type '" + type + "' not found. " + availableTypes);
    }

    const Inventory* inventory = manager->getSaleInventory();
    Director director;

    CustomerVisitor* visitor = nullptr;
    mt19937 rng;

    vector<string> v;
    v.push_back("easy");
    v.push_back("medium");
    v.push_back("hard");

    uniform_int_distribution<size_t> dist(0, v.size() - 1);
    string chosen;
    CustomerBuilder* builder = nullptr;
    
    for (int i = 0; i < num; i++) 
    {
        if(builder)
        {
            delete builder;
            builder = nullptr;
        }
        
        if(visitor)
        {
            delete visitor;
            visitor = nullptr;
        }
        
        if (type == "average") 
        {
            builder = new AverageCustomerBuilder(config);
        } 
        else if (type == "ignorant") 
        {
            builder = new IgnorantCustomerBuilder(config);
        } 
        else if (type == "greenfinger") 
        {
            builder = new GreenFingerCustomerBuilder(config);
        } 
        else 
        {
            throw runtime_error("Unknown customer type: " + type);
        }
        
        chosen = v[dist(rng)];

        if(chosen == "easy")
        {
            visitor = new VisitEasyCustomer(*inventory);
        }
        else if(chosen == "medium")
        {
            visitor = new VisitMediumCustomer(*inventory);
        }
        else // default to hard
        {
            visitor = new VisitHighCustomer(*inventory);
        }

        director.setBuilder(builder);
        Customer* customer = director.construct(*visitor);
        
        customers.push_back(customer);
    }

    if(builder)
    {
        delete builder;
    }

    if(visitor)
    {
        delete visitor;
    }

    logger->newLog("+ Created " + to_string(num) + " " + type + " customers");
}

vector<Customer*> Game::getCustomers()
{
    return customers;
}

map<string, map<string, vector<string>>> Game::getAvailableCustomerTypes()
{
    return config->getCustomerTypes();
}

string Game::getCustomersAsJson()
{
    stringstream jsonArray;
    jsonArray << "[";
    
    for (size_t i = 0; i < customers.size(); ++i) 
    {
        if (i > 0) 
        {
            jsonArray << ",";
        }

        jsonArray << customers[i]->getStructure();
    }
    
    jsonArray << "]";
    
    return jsonArray.str();
}

void Game::exitGame()
{
    logger->newLog("Exiting game...");
}