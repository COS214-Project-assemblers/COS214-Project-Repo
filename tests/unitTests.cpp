
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "Game.h"
#include "NewGameOption.h"
#include "PlayerMenu.h"
#include "MenuOption.h"
#include "BasicLogger.h"
#include "PlantCreator.h"
#include "SucculentCreator.h"
#include "FlowerCreator.h"
#include "TreeCreator.h"
#include "Plant.h"

TEST(GameTests, NewGameExecutesProperly) {
    // Set up environment
    Game* game = new Game;
    PlayerMenu* playerMenu = new PlayerMenu();
    BasicLogger* logger = new BasicLogger();
    NewGameOption* newGameOption = new NewGameOption(game, logger);

    // Perform actions
    playerMenu->setMenuOption(newGameOption);
    playerMenu->executeOption();

    // Verify expected outcomes

    // Get Factories
    vector<PlantCreator*> factories = game->getFactories();
    for (PlantCreator* factory : factories) {
        EXPECT_TRUE(factory->hasPlant()) << "Each factory should return true when the hasPlant() method is called";
    }

    // Test factories creation
    for (PlantCreator* factory : factories) {
        Plant* factPlant = factory->clonePlant();
        EXPECT_NE(factPlant, nullptr) << "Test each factory by calling clonePlant(), returning nullptr indicates failure";
        delete factPlant;
    }

    // Cleanup
    delete game;
    delete playerMenu;
    delete logger;
    // Note: don't delete newGameOption if PlayerMenu takes ownership
}