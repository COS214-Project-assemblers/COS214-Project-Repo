
#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "NewGameOption.h"
#include "PlayerMenu.h"
#include "MenuOption.h"
#include "BasicLogger.h"
#include "EnvironmentInitializer.h"

void testNewGame() {
    // Set up environment Game, PlayerMenu
    Game* game = new Game("../config/GameConfig.json");
    PlayerMenu* playerMenu = new PlayerMenu();
    BasicLogger* logger = new BasicLogger();
    NewGameOption* newGameOption = new NewGameOption(game, logger);

    // Perform actions
    playerMenu->setMenuOption(newGameOption);
    playerMenu->executeOption();

    // Free memory
    delete game;
    delete playerMenu;
    delete logger;
    // delete newGameOption; !!! Freeing option mem on deletion of PlayerMenu, not sure if that is right move !!!
}

TEST(UtilTests, TestSetEnv) {
    EnvironmentInitializer* envInitializer = new EnvironmentInitializer("../config/.env.local");
    envInitializer->initEnv();

    const char* logEnv = getenv("LOG_FILE");
    ASSERT_NE(logEnv, nullptr);
    cout << logEnv << endl;

    const char* gameConfEnv = getenv("GAME_CONFIG_PATH");
    ASSERT_NE(gameConfEnv, nullptr);
    cout << gameConfEnv << endl;

    delete envInitializer;
}

// int main(int argc, char **argv) {
//     testNewGame();
// }