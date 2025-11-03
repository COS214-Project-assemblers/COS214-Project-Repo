/**
 * @file NewGameOption.h
 * @brief Header file for NewGameOption class
 * @author Gerard Jordaan
 */

#ifndef NEW_GAME_OPT
#define NEW_GAME_OPT    

#include "MenuOption.h"

/**
 * @class NewGameOption
 * @brief Command for creating a new game instance
 * @details Implements MenuOption interface to handle new game creation
 * with logging capabilities. Follows the Command pattern.
 * 
 * @see MenuOption
 */
class NewGameOption : public MenuOption {
    public:
        /**
         * @brief Constructor - initializes with game and optional logger
         * @param[in] game Game object reference
         * @param[in] logger Optional logger reference, defaults to nullptr
         */
        NewGameOption(Game* game, Logger* logger = nullptr);

        /**
         * @brief Executes the new game creation command
         * @details Invokes the createNewGame method on the Game object
         * and logs the operation if logger is provided
         */
        virtual void execute() override;
};

#endif
