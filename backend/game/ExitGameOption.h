/**
 * @file ExitGameOption.h
 * @brief Command for exiting the game with logging capabilities
 * @author Gerard Jordaan
 */

#ifndef EXITGAMEOPT
#define EXITGAMEOPT

#include "MenuOption.h"

/**
 * @class ExitGameOption
 * @brief Command participant for encapsulating the command of exiting the game
 * @details Allows for advanced logging and obvious error handling. Follows the
 * Command pattern to encapsulate the exit game operation.
 * 
 * @see MenuOption
 * @see CommandPattern
 */
class ExitGameOption : public MenuOption {
    public:

        /**
         * @brief Constructor - initializes with game and optional logger
         * @param game Pointer to the Game instance
         * @param logger Optional logger for command execution logging
         */
        ExitGameOption(Game* game, Logger* logger = nullptr);

        /**
         * @brief Executes the exit game command
         * @details Logs the operation and calls game->exitGame()
         */
        virtual void execute() override;
};

#endif


