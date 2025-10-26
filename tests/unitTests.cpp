
#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

#include "Game.h"
#include "NewGameOption.h"
#include "PlayerMenu.h"
#include "MenuOption.h"
#include "BasicLogger.h"
#include "EnvironmentInitializer.h"
#include "PlantCreator.h"
#include "SucculentCreator.h"
#include "FlowerCreator.h"
#include "TreeCreator.h"
#include "Plant.h"

TEST(GameCreationTests, NewGameOptionExecutesProperly) {
    // Set up environment
    std::string configPath = std::string(ROOT_SOURCE_DIR) + "/config/GameConfig.json";
    Game* game = new Game(configPath); 
    PlayerMenu* playerMenu = new PlayerMenu();
    BasicLogger* logger = new BasicLogger();
    NewGameOption* newGameOption = new NewGameOption(game, logger);

    // Perform actions
    playerMenu->setMenuOption(newGameOption);
    playerMenu->executeOption();
    
    // Cleanup
    delete game;
    delete playerMenu;
    delete logger;
    // Note: don't delete newGameOption if PlayerMenu takes ownership
}

TEST(GameCreationTests, TestFactoriesNotNull) {
    std::string configPath = std::string(ROOT_SOURCE_DIR) + "/config/GameConfig.json";
    Game* game = new Game(configPath); 
    PlayerMenu* playerMenu = new PlayerMenu();
    BasicLogger* logger = new BasicLogger();
    NewGameOption* newGameOption = new NewGameOption(game, logger);

    playerMenu->setMenuOption(newGameOption);
    playerMenu->executeOption();

    // Get Factories
    map<string, PlantCreator*> factories = game->getFactories();

    for (auto it = factories.begin(); it != factories.end(); ++it) {
        EXPECT_TRUE(it->second->hasPlant()) << "If factory does not have plant, factory creation failed";
    }

    delete game;
    delete playerMenu;
    delete logger;
}

TEST(GameCreationTests, TestFactoriesPlantCreation) {
    std::string configPath = std::string(ROOT_SOURCE_DIR) + "/config/GameConfig.json";
    Game* game = new Game(configPath); 
    PlayerMenu* playerMenu = new PlayerMenu();
    BasicLogger* logger = new BasicLogger();
    NewGameOption* newGameOption = new NewGameOption(game, logger);

    playerMenu->setMenuOption(newGameOption);
    playerMenu->executeOption();

    map<string, PlantCreator*> factories = game->getFactories();

    // Test factories plant creation
    for (auto it = factories.begin(); it != factories.end(); ++it) {
        Plant* factPlant = it->second->clonePlant();
        EXPECT_NE(factPlant, nullptr) << "Test each factory by calling clonePlant(), returning nullptr indicates failure";
        delete factPlant;
    }

    delete game;
    delete playerMenu;
    delete logger;
}