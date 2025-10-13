#ifndef CONTINUE_GAME_OPT
#define CONTINUE_GAME_OPT

#include "MenuOption.h"
#include "Game.h"

class ContinueGameOption : public MenuOption {
    private:
        Game* game;
        int gameId;
    public:
        ContinueGameOption(Game* game, int gameId);
        virtual void execute();
};

#endif // CONTINUE_GAME_OPT