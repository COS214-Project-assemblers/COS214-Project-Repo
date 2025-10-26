
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <map>

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
    Game* game = new Game("../config/GameConfig.json");
    PlayerMenu* playerMenu = new PlayerMenu();
    BasicLogger* logger = new BasicLogger();
    NewGameOption* newGameOption = new NewGameOption(game, logger);

    // Perform actions
    playerMenu->setMenuOption(newGameOption);
    playerMenu->executeOption();

    // Verify expected outcomes

    // Get Factories
    map<string, PlantCreator*> factories = game->getFactories();

    for (auto it = factories.begin(); it != factories.end(); ++it) {
        EXPECT_TRUE(it->second->hasPlant());
    }

    // Test factories creation
    for (auto it = factories.begin(); it != factories.end(); ++it) {
        Plant* factPlant = it->second->clonePlant();
        EXPECT_NE(factPlant, nullptr) << "Test each factory by calling clonePlant(), returning nullptr indicates failure";
        delete factPlant;
    }

    // Test Buy Plant
    
    // Cleanup
    delete game;
    delete playerMenu;
    delete logger;
    // Note: don't delete newGameOption if PlayerMenu takes ownership
    std::cout << std::endl;
}

TEST(PlantFactoryTests, SucculentCreationAndCloning)
{
    // Test Succulent creation through factory
    SucculentCreator succulentCreator;
    succulentCreator.makePlant("Cactus");
    
    EXPECT_TRUE(succulentCreator.hasPlant()) << "Succulent creator should have a plant after makePlant()";
    
    Plant* succulent = succulentCreator.getPlant();
    EXPECT_NE(succulent, nullptr) << "getPlant() should return non-null pointer for Succulent";
    EXPECT_EQ(succulent->getPlantCategory(), "Succulent") << "Succulent plant should have category 'Succulent'";
    EXPECT_EQ(succulent->getPlantVariety(), "Cactus") << "Succulent variety should be 'Cactus'";
    
    std::cout << "✓ Succulent factory created plant with category: " << succulent->getPlantCategory() 
              << ", variety: " << succulent->getPlantVariety() << std::endl;
    
    // Test cloning functionality
    Plant* clonedSucculent = succulent->clone();
    EXPECT_NE(clonedSucculent, nullptr) << "clone() should return non-null pointer";
    EXPECT_NE(succulent, clonedSucculent) << "Clone should be a different object from original";
    EXPECT_EQ(clonedSucculent->getPlantCategory(), "Succulent") << "Cloned succulent should have same category";
    EXPECT_EQ(clonedSucculent->getPlantVariety(), "Cactus") << "Cloned succulent should have same variety";
    
    std::cout << "✓ Succulent cloning successful - original and clone are different objects with same properties" << std::endl;
    
    delete clonedSucculent;
}