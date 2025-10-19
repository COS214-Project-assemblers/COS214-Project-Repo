/**
 * @file ContinueGameOption.h
 * @brief Header file for ContinueGameOption class
 * @author Gerard Jordaan
 */

#ifndef CONTINUE_GAME_OPT
#define CONTINUE_GAME_OPT

#include "MenuOption.h"

/**
 * @class ContinueGameOption
 * @brief Inherits from MenuOption. Represents ConcreteCommand participant
 *  in the Command design pattern. Invokes operation to load a saved game.
 */
class ContinueGameOption : public MenuOption {
    private:
        /**
         * @brief Attribute specific to this class within the Command hierarchy
         * . GameId used to lookup game data in the database.
         */
        int gameId;
    public:
        /**
         * @brief Calls parent constructor and sets gameId attribute
         * @param[in] game Game object reference
         * @param[in] gameId GameId of saved game
         * @param[in] logger Optional reference to Logger object, default is nullptr
         */
        ContinueGameOption(Game* game, int gameId, Logger* logger = nullptr);
        /**
         * @brief Implements execute method from MenuOption interface. Invokes
         *  operation on Game object to load an existing game
         */
        virtual void execute() override;
};

#endif // CONTINUE_GAME_OPT