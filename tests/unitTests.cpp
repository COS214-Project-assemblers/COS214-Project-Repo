
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
#include "PlantHealth.h"
#include "Plant.h"
#include "Succulent.h"
/*
void testNewGame() {
    // Set up environment Game, PlayerMenu
    Game* game = new Game("../config/GameConfig.json");
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

int main(int argc, char **argv) {
    testNewGame();
}
*/
TEST(TestSuiteName, TestName) {
    // Setup
    
    Health h(1.0f, 1.0f, 1.0f, 0);

    // Action
    h.decay(0);

    // Check results
    EXPECT_LT(h.healthScore(), 3.0f);  // after decay, total health should drop (should be Less Than (LT))
}

TEST(PlantDynamicTest, HealthChangesOverTime) {
    Plant* myPlant = new Succulent("Aloe");

    float initialScore = myPlant->healthScore();

    myPlant->start();
    std::this_thread::sleep_for(std::chrono::seconds(10)); // let decay happen
    myPlant->stop(); // force the thread to stop
    myPlant->join();

    float laterScore = myPlant->healthScore();

    EXPECT_LT(laterScore, initialScore) << "Health should decay over time!";
    delete myPlant;
}
