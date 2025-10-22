#include "Game.h"
#include "Greenhouse.h"
#include "PlantCreator.h"
#include "FlowerCreator.h"
#include "SucculentCreator.h"
#include "TreeCreator.h"

Game::Game() {
    // Nothing yet
}

void Game::setGreenhouse(Greenhouse* greenhouse) {
    this->greenhouse = greenhouse;
}

Greenhouse* Game::getGreenhouse() {
    return greenhouse;
}

void Game::setFactories(vector<PlantCreator*> factories) {
    this->factories = factories;
}

vector<PlantCreator*> Game::getFactories() {
    return factories;
}

void Game::createNewGame() {
    // try 
    try {
        // Create new factories
        vector<PlantCreator*> factories;
        factories.push_back(new SucculentCreator());
        factories.push_back(new FlowerCreator());
        factories.push_back(new TreeCreator());

        setFactories(factories);
        
        cout << "+ Created factories" << endl;
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
    for (PlantCreator* factory : factories) {
        delete factory;
    }
}