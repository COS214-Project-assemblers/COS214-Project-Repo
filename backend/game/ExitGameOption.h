/**
 * @file ExitGameOption.h
 * @author Gerard Jordaan
 */

#ifndef EXITGAMEOPT
#define EXITGAMEOPT

#include "MenuOption.h"

/**
 * @class ExitGameOption
 * @brief Command participant for encapsulating the command of exiting the game
 *  allows for advanced logging and obvious error handling
 */
class ExitGameOption : public MenuOption {
    public:
        /**
         * @brief Calls parent constructor with passed in params
         */
        ExitGameOption(Game* game, Logger* logger = nullptr);
        /**
         * @brief Logs and executes game->exitGame()
         */
        virtual void execute() override;
};

#endif


