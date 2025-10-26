#include "Game.h"
#include "Greenhouse.h"
#include "PlantCreator.h"
#include "FlowerCreator.h"
#include "SucculentCreator.h"
#include "TreeCreator.h"
#include "JSONGameConfiguration.h"

Game::Game(string configPath) {
    try {
        config = new JSONGameConfiguration(configPath);
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    } catch (...) {
        cout << "Failed to init config for unknown reason" << endl;
        cout << "Exiting..." << endl;
        exit(EXIT_FAILURE);
    }
}

void Game::setGreenhouse(Greenhouse* greenhouse) {
    this->greenhouse = greenhouse;
}

Greenhouse* Game::getGreenhouse() {
    return greenhouse;
}

void Game::setFactories(map<string, PlantCreator*> factories) {
    this->factories = factories;
}

map<string, PlantCreator*> Game::getFactories() {
    return factories;
}

void Game::createNewGame() {
    // try 
    try {
        // Create new factories
        map<string, vector<string>> varieties;
        
        varieties = config->getPlantVarieties();
        for (const auto& [category, variants] : varieties) {
            std::cout << category << ": ";
            for (const auto& v : variants) std::cout << v << " ";
            std::cout << "\n";
        }

        cout << "Created factories" << endl;
    } catch (...) { // More specific error handling required
        throw runtime_error("Failed to create factories for unknown reason"); // Reason is unknown since using catch(...)
    }
    
    try {
        setGreenhouse(new Greenhouse());
        cout << "+ Creating greenhouse" << endl;
    } catch (...) {
        throw runtime_error("Failed to create greenhouse for unknown reason");
    }
}

void Game::buyPlants(string plant, int num) {}

void Game::loadExistingGame() {}

void Game::saveGame() {}

Game::~Game() {
    // for (PlantCreator* factory : factories) {
    //     delete factory;
    // }
    for (auto it = factories.begin(); it != factories.end(); ++it) {
        delete it->second;
    }
}