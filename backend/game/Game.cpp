#include "Game.h"
#include "Greenhouse.h"
#include "PlantCreator.h"
#include "FlowerCreator.h"
#include "SucculentCreator.h"
#include "TreeCreator.h"
#include "JSONGameConfiguration.h"
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

void Game::buyPlants(string plant, int num) {}

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

    if (config != nullptr)
    {
        delete config;
    }

    if (greenhouse != nullptr)
    {
        delete greenhouse;
    }
}