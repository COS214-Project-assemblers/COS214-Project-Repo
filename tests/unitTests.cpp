
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
}

TEST(PlantTests, PlantCreation)
{
    // Test Succulent creation
    SucculentCreator succulentCreator;
    succulentCreator.makePlant("Cactus");
    
    EXPECT_TRUE(succulentCreator.hasPlant());
    
    Plant* succulent = succulentCreator.getPlant();
    EXPECT_NE(succulent, nullptr);
    EXPECT_EQ(succulent->getPlantCategory(), "Succulent");
    EXPECT_EQ(succulent->getPlantVariety(), "Cactus");
    
    // Test cloning succulent
    Plant* clonedSucculent = succulent->clone();
    EXPECT_NE(clonedSucculent, nullptr);
    EXPECT_NE(succulent, clonedSucculent); // Should be different objects
    EXPECT_EQ(clonedSucculent->getPlantCategory(), "Succulent");
    EXPECT_EQ(clonedSucculent->getPlantVariety(), "Cactus");
    
    delete clonedSucculent;

    // Test Flower creation
    FlowerCreator flowerCreator;
    flowerCreator.makePlant("Rose");
    
    EXPECT_TRUE(flowerCreator.hasPlant());
    
    Plant* flower = flowerCreator.getPlant();
    EXPECT_NE(flower, nullptr);
    EXPECT_EQ(flower->getPlantCategory(), "Flower");
    EXPECT_EQ(flower->getPlantVariety(), "Rose");
    
    // Test cloning flower
    Plant* clonedFlower = flower->clone();
    EXPECT_NE(clonedFlower, nullptr);
    EXPECT_NE(flower, clonedFlower);
    EXPECT_EQ(clonedFlower->getPlantCategory(), "Flower");
    EXPECT_EQ(clonedFlower->getPlantVariety(), "Rose");
    
    delete clonedFlower;

    // Test Tree creation
    TreeCreator treeCreator;
    treeCreator.makePlant("Lemon");
    
    EXPECT_TRUE(treeCreator.hasPlant());
    
    Plant* tree = treeCreator.getPlant();
    EXPECT_NE(tree, nullptr);
    EXPECT_EQ(tree->getPlantCategory(), "Tree");
    EXPECT_EQ(tree->getPlantVariety(), "Lemon");
    
    // Test cloning tree
    Plant* clonedTree = tree->clone();
    EXPECT_NE(clonedTree, nullptr);
    EXPECT_NE(tree, clonedTree);
    EXPECT_EQ(clonedTree->getPlantCategory(), "Tree");
    EXPECT_EQ(clonedTree->getPlantVariety(), "Lemon");
    
    delete clonedTree;
}