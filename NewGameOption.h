/**
 * @file NewGameOption.h
 * @brief Header file for NewGameOption class
 * @author Gerard Jordaan
 */
#ifndef NEW_GAME_OPT
#define NEW_GAME_OPT    

#include "MenuOption.h"
#include "Game.h"

/**
 * @class NewGameOption
 * @brief Ne
class NewGameOption : public MenuOption {
    private:
        Game* game;
    public:
        NewGameOption(Game* game);
        virtual void execute();
};

#endif // NEW_GAME_OPT
