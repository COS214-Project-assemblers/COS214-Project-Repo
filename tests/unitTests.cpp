
#include <gtest/gtest.h>
#include <iostream>
#include "API.h"
#include "Game.h"
#include "NewGameOption.h"
#include "PlayerMenu.h"
#include "MenuOption.h"
#include "BasicLogger.h"

void testNewGame() {
    // Set up environment Game, PlayerMenu
    Game* game = new Game;
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

int main(int argc, char **argv) {
    testNewGame();
}