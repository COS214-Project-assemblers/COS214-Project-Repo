
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
    std::string configPath = std::string(ROOT_SOURCE_DIR) + "/config/API/GameConfig.json";
    Game* game = new Game(configPath); // VSCode will shout, dont worry
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

    std::cout << std::endl;
}

TEST(PlantFactoryTests, FlowerCreationAndCloning)
{
    // Test Flower creation through factory
    FlowerCreator flowerCreator;
    flowerCreator.makePlant("Rose");
    
    EXPECT_TRUE(flowerCreator.hasPlant()) << "Flower creator should have a plant after makePlant()";
    
    Plant* flower = flowerCreator.getPlant();
    EXPECT_NE(flower, nullptr) << "getPlant() should return non-null pointer for Flower";
    EXPECT_EQ(flower->getPlantCategory(), "Flower") << "Flower plant should have category 'Flower'";
    EXPECT_EQ(flower->getPlantVariety(), "Rose") << "Flower variety should be 'Rose'";
    
    std::cout << "✓ Flower factory created plant with category: " << flower->getPlantCategory() 
              << ", variety: " << flower->getPlantVariety() << std::endl;
    
    // Test cloning functionality
    Plant* clonedFlower = flower->clone();
    EXPECT_NE(clonedFlower, nullptr) << "clone() should return non-null pointer";
    EXPECT_NE(flower, clonedFlower) << "Clone should be a different object from original";
    EXPECT_EQ(clonedFlower->getPlantCategory(), "Flower") << "Cloned flower should have same category";
    EXPECT_EQ(clonedFlower->getPlantVariety(), "Rose") << "Cloned flower should have same variety";
    
    std::cout << "✓ Flower cloning successful - original and clone are different objects with same properties" << std::endl;
    
    delete clonedFlower;

    std::cout << std::endl;
}

TEST(PlantFactoryTests, TreeCreationAndCloning)
{
    // Test Tree creation through factory
    TreeCreator treeCreator;
    treeCreator.makePlant("Lemon");
    
    EXPECT_TRUE(treeCreator.hasPlant()) << "Tree creator should have a plant after makePlant()";
    
    Plant* tree = treeCreator.getPlant();
    EXPECT_NE(tree, nullptr) << "getPlant() should return non-null pointer for Tree";
    EXPECT_EQ(tree->getPlantCategory(), "Tree") << "Tree plant should have category 'Tree'";
    EXPECT_EQ(tree->getPlantVariety(), "Lemon") << "Tree variety should be 'Lemon'";
    
    std::cout << "✓ Tree factory created plant with category: " << tree->getPlantCategory() 
              << ", variety: " << tree->getPlantVariety() << std::endl;
    
    // Test cloning functionality
    Plant* clonedTree = tree->clone();
    EXPECT_NE(clonedTree, nullptr) << "clone() should return non-null pointer";
    EXPECT_NE(tree, clonedTree) << "Clone should be a different object from original";
    EXPECT_EQ(clonedTree->getPlantCategory(), "Tree") << "Cloned tree should have same category";
    EXPECT_EQ(clonedTree->getPlantVariety(), "Lemon") << "Cloned tree should have same variety";
    
    std::cout << "✓ Tree cloning successful - original and clone are different objects with same properties" << std::endl;
    
    delete clonedTree;

    std::cout << std::endl;
}

TEST(PlantFactoryTests, AllPlantTypesHaveCorrectCategories)
{
    std::cout << "\n=== Testing All Plant Factory Categories ===" << std::endl;
    
    // Test that each creator creates the correct type of plant
    SucculentCreator succulentCreator;
    FlowerCreator flowerCreator;
    TreeCreator treeCreator;
    
    // Test plant creation with different varieties
    succulentCreator.makePlant("Aloe");
    flowerCreator.makePlant("Daisy");
    treeCreator.makePlant("Oak");
    
    EXPECT_TRUE(succulentCreator.hasPlant()) << "Succulent creator should have plant";
    EXPECT_TRUE(flowerCreator.hasPlant()) << "Flower creator should have plant";
    EXPECT_TRUE(treeCreator.hasPlant()) << "Tree creator should have plant";
    
    // Test that we can get the plants
    Plant* succulent = succulentCreator.getPlant();
    Plant* flower = flowerCreator.getPlant();
    Plant* tree = treeCreator.getPlant();
    
    EXPECT_NE(succulent, nullptr) << "Succulent should not be null";
    EXPECT_NE(flower, nullptr) << "Flower should not be null";
    EXPECT_NE(tree, nullptr) << "Tree should not be null";
    
    // Test categories
    EXPECT_EQ(succulent->getPlantCategory(), "Succulent") << "Succulent category mismatch";
    EXPECT_EQ(flower->getPlantCategory(), "Flower") << "Flower category mismatch";
    EXPECT_EQ(tree->getPlantCategory(), "Tree") << "Tree category mismatch";
    
    std::cout << "✓ All factories created correct plant types:" << std::endl;
    std::cout << "  - Succulent: " << succulent->getPlantCategory() << " (" << succulent->getPlantVariety() << ")" << std::endl;
    std::cout << "  - Flower: " << flower->getPlantCategory() << " (" << flower->getPlantVariety() << ")" << std::endl;
    std::cout << "  - Tree: " << tree->getPlantCategory() << " (" << tree->getPlantVariety() << ")" << std::endl;

    std::cout << std::endl;
}

TEST(PlantFactoryTests, FactoryCloneMethodWorksCorrectly)
{
    std::cout << "\n=== Testing Factory Clone Method ===" << std::endl;
    
    // Test the clonePlant method from PlantCreator
    SucculentCreator succulentCreator;
    succulentCreator.makePlant("Cactus");
    
    EXPECT_TRUE(succulentCreator.hasPlant()) << "Creator should have plant before cloning";
    
    // Test cloning through the creator's clonePlant method
    Plant* clonedPlant = succulentCreator.clonePlant();
    EXPECT_NE(clonedPlant, nullptr) << "clonePlant() should return non-null pointer";
    EXPECT_NE(succulentCreator.getPlant(), clonedPlant) << "Cloned plant should be different object from factory's plant";
    
    // Verify cloned plant has same properties
    EXPECT_EQ(clonedPlant->getPlantCategory(), "Succulent") << "Cloned plant category should match";
    EXPECT_EQ(clonedPlant->getPlantVariety(), "Cactus") << "Cloned plant variety should match";
    
    std::cout << "✓ Factory clonePlant() method works correctly" << std::endl;
    std::cout << "  Original: " << succulentCreator.getPlant()->getPlantCategory() 
              << " (" << succulentCreator.getPlant()->getPlantVariety() << ")" << std::endl;
    std::cout << "  Clone: " << clonedPlant->getPlantCategory() 
              << " (" << clonedPlant->getPlantVariety() << ")" << std::endl;
    
    delete clonedPlant;

    std::cout << std::endl;
}

TEST(PlantFactoryTests, EmptyFactoryBehavior)
{
    std::cout << "\n=== Testing Empty Factory Behavior ===" << std::endl;
    
    // Test behavior when no plant has been created
    SucculentCreator* creator = new SucculentCreator();
    
    EXPECT_FALSE(creator->hasPlant()) << "New creator should not have plant initially";
    EXPECT_EQ(creator->getPlant(), nullptr) << "getPlant() should return nullptr for empty creator";
    EXPECT_EQ(creator->clonePlant(), nullptr) << "clonePlant() should return nullptr for empty creator";
    
    std::cout << "✓ Empty factory behavior correct - all methods return expected null values" << std::endl;

    delete creator;

    std::cout << std::endl;
}

TEST(PlantFactoryTests, MultiplePlantCreationsReplacePrevious)
{
    std::cout << "\n=== Testing Multiple Creations ===" << std::endl;
    
    FlowerCreator creator;
    
    // First creation
    creator.makePlant("Rose");
    EXPECT_TRUE(creator.hasPlant()) << "Creator should have plant after first makePlant()";
    Plant* firstPlant = creator.getPlant();
    EXPECT_NE(firstPlant, nullptr) << "First plant should not be null";
    EXPECT_EQ(firstPlant->getPlantVariety(), "Rose") << "First plant should be Rose";
    
    std::cout << "✓ First plant created: " << firstPlant->getPlantVariety() << std::endl;
    
    // Second creation should replace the first
    creator.makePlant("Tulip");
    EXPECT_TRUE(creator.hasPlant()) << "Creator should still have plant after second makePlant()";
    Plant* secondPlant = creator.getPlant();
    EXPECT_NE(secondPlant, nullptr) << "Second plant should not be null";
    EXPECT_EQ(secondPlant->getPlantVariety(), "Tulip") << "Second plant should be Tulip (replaced Rose)";
    
    std::cout << "✓ Second plant replaced first: " << secondPlant->getPlantVariety() << std::endl;

    std::cout << std::endl;
}

TEST(PlantFactoryTests, ComprehensiveFactoryAndPrototypeIntegration)
{
    std::cout << "\n=== Comprehensive Factory + Prototype Test ===" << std::endl;
    
    // Test all factories in sequence
    std::vector<std::pair<std::string, PlantCreator*>> factories = {
        {"Succulent", new SucculentCreator()},
        {"Flower", new FlowerCreator()},
        {"Tree", new TreeCreator()}
    };
    
    std::vector<std::string> varieties = {"Jade Plant", "Orchid", "Maple"};
    
    for (size_t i = 0; i < factories.size(); ++i) 
    {
        auto& [factoryName, creator] = factories[i];
        std::string variety = varieties[i];
        
        creator->makePlant(variety);
        EXPECT_TRUE(creator->hasPlant()) << factoryName << " creator should have plant";
        
        Plant* original = creator->getPlant();
        EXPECT_NE(original, nullptr) << factoryName << " plant should not be null";
        
        // Test cloning through both methods
        Plant* clone1 = original->clone();
        Plant* clone2 = creator->clonePlant();
        
        EXPECT_NE(clone1, nullptr) << factoryName << " clone via plant method should not be null";
        EXPECT_NE(clone2, nullptr) << factoryName << " clone via factory method should not be null";
        EXPECT_NE(original, clone1) << factoryName << " clone should be different object";
        EXPECT_NE(original, clone2) << factoryName << " factory clone should be different object";
        
        // All should have same properties
        EXPECT_EQ(original->getPlantCategory(), clone1->getPlantCategory());
        EXPECT_EQ(original->getPlantVariety(), clone1->getPlantVariety());
        EXPECT_EQ(original->getPlantCategory(), clone2->getPlantCategory());
        EXPECT_EQ(original->getPlantVariety(), clone2->getPlantVariety());
        
        std::cout << "✓ " << factoryName << " factory: " << original->getPlantCategory() 
                  << " (" << original->getPlantVariety() << ") - cloning works both ways" << std::endl;
        
        delete clone1;
        delete clone2;
        delete creator;
    }

    std::cout << std::endl;
}

TEST(GameCreationTests, TestFactoriesNotNull) {
    std::string configPath = std::string(ROOT_SOURCE_DIR) + "/config/API/GameConfig.json";
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
    std::string configPath = std::string(ROOT_SOURCE_DIR) + "/config/API/GameConfig.json";
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