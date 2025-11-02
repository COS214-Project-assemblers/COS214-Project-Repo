#include "NewGameOption.h"

NewGameOption::NewGameOption(Game* game, Logger* logger)
: MenuOption(game, logger) {}

void NewGameOption::execute() {
    try {
        if (logger != nullptr) logger->newLog("Creating new game");
        game->createNewGame();
        if (logger != nullptr) logger->newLog("Successfully created new game");
    } catch (const std::exception& e) {
        if (logger != nullptr) logger->newLog("Failed to create new game");
        throw e;
    }
}