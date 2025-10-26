#include "Game.h"
#include "Greenhouse.h"
#include "PlantCreator.h"
#include "FlowerCreator.h"
#include "SucculentCreator.h"
#include "TreeCreator.h"
#include "JSONGameConfiguration.h"

Game::Game(string configPath)
{
    try
    {
        config = new JSONGameConfiguration(configPath);
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    catch (const out_of_range &e)
    {
        cout << e.what() << endl;
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    }
    catch (...)
    {
        cout << "Failed to init config for unknown reason" << endl;
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

void createFactoriesHelper(string category, vector<string> variants, map<string, PlantCreator *>& factories)
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
        cout << "+ Made " + category + " factory for variety [" + v + "]" << endl;
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
            createFactoriesHelper(category, variants, factories);
        }

        setFactories(factories);

        cout << "+ Created factories" << endl;
    }
    catch (...)
    {                                                                         // More specific error handling required
        throw runtime_error("Failed to create factories for unknown reason"); // Reason is unknown since using catch(...)
    }

    try
    {
        setGreenhouse(new Greenhouse());
        cout << "+ Created greenhouse" << endl;
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
    for (auto it = factories.begin(); it != factories.end(); ++it)
    {
        delete it->second;
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