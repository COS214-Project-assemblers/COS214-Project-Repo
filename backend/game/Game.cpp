#include "Game.h"
#include "Greenhouse.h"
#include "PlantCreator.h"
#include "FlowerCreator.h"
#include "SucculentCreator.h"
#include "TreeCreator.h"
#include "CustomerCreator.h"
#include "JSONGameConfiguration.h"
#include "IgnorantCustomerCreator.h"
#include "AverageCustomerCreator.h"
#include "GreenFingerCustomerCreator.h"
#include "BasicLogger.h"
#include "LogDecorator.h"
#include "CoutAndLog.h"

Game::Game(string configPath)
{
    CoutAndLog* logDec = new CoutAndLog();
    logDec->setBaseLogger(new BasicLogger());
    logger = logDec;

    try
    {
        logger->newLog("Attempting to load JSON game configuration " + configPath);
        config = new JSONGameConfiguration(configPath);

        map<string, vector<string>> varieties = config->getPlantVarieties();
        for (const auto &[category, variants] : varieties)
        {
            for (const auto &variety : variants)
            {
                varietyToCategory[variety] = category;
                cout << "✓ Mapped variety '" << variety << "' to category '" << category << "'" << endl;
            }
        }
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

void createFactoriesHelper(string category, vector<string> variants, map<string, PlantCreator *>& factories, Logger* logger)
{
    for (const auto &v : variants)
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

        newPlantCreator->makePlant(v);
        string message = "+ Made " + category + " factory for variety [" + v + "]";
        logger->newLog(message);
        factories[v] = newPlantCreator;
    }
}

void Game::createNewGame()
{
    // try
    try
    {
        // Create new factories
        map<string, vector<string>> varieties;
        map<string, PlantCreator *> factories;

        varieties = config->getPlantVarieties();
        for (const auto &[category, variants] : varieties)
        {
            createFactoriesHelper(category, variants, factories, logger);
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

    for (auto it = customerFactories.begin(); it != customerFactories.end(); ++it)
    {
        delete it->second;
    }

    for (auto customer : customers)
    {
        delete customer;
    }

    if (config != nullptr)
    {
        delete config;
    }

    if (greenhouse != nullptr)
    {
        delete greenhouse;
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

map<string, vector<string>> Game::getAvailablePlantVarieties() 
{
    return config->getPlantVarieties();
}

void Game::createCustomerFactories()
{
    try
    {
        customerFactories["ignorant"] = new IgnorantCustomerCreator();
        customerFactories["average"] = new AverageCustomerCreator();
        customerFactories["greenfinger"] = new GreenFingerCustomerCreator();
        
        cout << "+ Created customer factories" << endl;
    }
    catch (...)
    {
        throw runtime_error("Failed to create customer factories for unknown reason");
    }
}

void Game::addCustomers(string customerType, int num)
{
    if (num <= 0) 
    {
        throw runtime_error("Number of customers must be positive, got: " + to_string(num));
    }

    if (customerFactories.empty()) 
    {
        throw runtime_error("No customer factories available. Please create customer factories first.");
    }

    auto factoryIt = customerFactories.find(customerType);
    if (factoryIt == customerFactories.end()) 
    {
        string availableTypes = "Available customer types: ";
        for (const auto& [type, creator] : customerFactories) 
        {
            availableTypes += type + " ";
        }

        throw runtime_error("Customer type '" + customerType + "' not found. " + availableTypes);
    }

    // Get customer data from configuration
    auto customerTypes = getAvailableCustomerTypes();
    auto customerTypeData = customerTypes.find(customerType);
    
    if (customerTypeData == customerTypes.end() || customerTypeData->second.empty()) 
    {
        throw runtime_error("No customer data found for type: " + customerType);
    }

    CustomerCreator* factory = factoryIt->second;
    
    for (int i = 0; i < num; i++) 
    {
        const auto& customerRawData = customerTypeData->second[i % customerTypeData->second.size()];
        
        CustomerData customerData;
        customerData.name = customerRawData.at("name");
        customerData.introduce = customerRawData.at("introduce");
        customerData.preferences = customerRawData.at("preferences");
        customerData.recommendations = customerRawData.at("recommendations");
        customerData.accept = customerRawData.at("accept");
        customerData.reject = customerRawData.at("reject");
        customerData.acceptExit = customerRawData.at("acceptExit");
        customerData.rejectExit = customerRawData.at("rejectExit");
        customerData.type = customerType;
        
        factory->makeCustomer(customerData);
        Customer* newCustomer = factory->getCustomer();
        
        if (newCustomer != nullptr) 
        {
            customers.push_back(newCustomer);
            cout << "+ Added " << customerType << " customer: " << customerData.name << endl;
        } 
        else 
        {
            throw runtime_error("Failed to create customer of type: " + customerType);
        }
    }
    
    cout << "+ Successfully added " << num << " " << customerType << " customers" << endl;
}

vector<Customer*> Game::getCustomers()
{
    return customers;
}

map<string, vector<map<string, string>>> Game::getAvailableCustomerTypes()
{
    return config->getCustomerTypes();
}