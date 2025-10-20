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
 * @brief Implements MenuOption interface. NewGameOption invokes and logs the operation to create a new Game
 */
class NewGameOption : public MenuOption {
    public:
        /**
         * @brief Constructor sets attributes. Calls parent constructor
         * @param[in] game Game object reference
         * @param[in] logger Optional reference to Logger object, default is nullptr
         */
        NewGameOption(Game* game, Logger* logger = nullptr);
        /**
         * @brief Implements execute method from MenuOption interface.
         *  invokes the method on the Game object related to creating a new game
         */
        virtual void execute() override;
};

#endif // NEW_GAME_OPT
