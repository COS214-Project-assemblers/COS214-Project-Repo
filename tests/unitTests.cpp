
#include <gtest/gtest.h>
#include <iostream>
#include "../backend/API/API.h"
#include "../backend/game/Game.h"
#include "../backend/game/NewGameOption.h"
#include "../backend/game/PlayerMenu.h"
#include "../backend/game/MenuOption.h"

void testNewGame() {
    // Set up environment Game, PlayerMenu
    Game* game = new Game;
    PlayerMenu* playerMenu = new PlayerMenu();
    Logger* logger = new Logger();
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

int main(int argc, char **argv) {
    std::cout << std::getenv("LOG_FILE") << std::endl;
    testNewGame();
}