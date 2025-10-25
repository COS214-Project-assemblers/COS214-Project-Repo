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
        map<string,PlantCreator*> factories;

        // Get plants from database? Simulate that only now
        SucculentCreator* cactusCreator = new SucculentCreator();
        cactusCreator->makePlant("Cactus");
        factories["cactus"] = cactusCreator;

        FlowerCreator* dandelionCreator = new FlowerCreator();
        dandelionCreator->makePlant("Dandelion");
        factories["dandelion"] = dandelionCreator;

        TreeCreator* oakCreator = new TreeCreator();
        oakCreator->makePlant("Oak");
        factories["oak"] = oakCreator;

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
    // for (PlantCreator* factory : factories) {
    //     delete factory;
    // }
    for (auto it = factories.begin(); it != factories.end(); ++it) {
        delete it->second;
    }
}