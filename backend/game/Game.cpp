#include "Game.h"
#include "../greenhouse/Greenhouse.h"
#include "../plant/PlantCreator.h"
#include "../plant/FlowerCreator.h"
#include "../plant/SucculentCreator.h"
#include "../plant/TreeCreator.h"
#include "JSONGameConfiguration.h"

Game::Game(string configPath) {
    try {
        config = new JSONGameConfiguration(configPath);
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
        exit(EXIT_FAILURE);
    } catch (...) {
        cout << "Failed to init config for unknown reason" << endl;
        exit(EXIT_FAILURE);
    }
}

void Game::setGreenhouse(Greenhouse* greenhouse) {}

void Game::setFactories(vector<PlantCreator*> factories) {}

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
        // setGreenhouse(new Greenhouse());
        // Greenhouse not defined yet
        cout << "Creating greenhouse" << endl;
    } catch (...) {
        throw runtime_error("Failed to create greenhouse for unknown reason");
    }
}

void Game::buyPlants(string plant, int num) {}

void Game::loadExistingGame() {}

void Game::saveGame() {}

Game::~Game() {
    for (PlantCreator* factory : factories) {
        delete factory;
    }
}