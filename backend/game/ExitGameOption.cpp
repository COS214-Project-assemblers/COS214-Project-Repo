#include "ExitGameOption.h"

ExitGameOption::ExitGameOption(Game* game, Logger* logger)
    : MenuOption(game, logger) {}

void ExitGameOption::execute()
{
    logger->newLog("Attempting to EXIT Game");
    game->exitGame();
    logger->newLog("Successfully EXITED Game");
}