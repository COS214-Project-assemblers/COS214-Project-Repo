#ifndef M_OPTION
#define M_OPTION

#include "Game.h"
#include "Logger.h"

class MenuOption {
    protected:
        /**
         * @brief Reference to Game object. Needed to invoke method according to option
         */
        Game* game;
        /**
         * @brief Reference to Logger object. Optional (can be unused). Reference used to create
         *  new Log entries
         */
        Logger* logger;
    public:
        /**
         * @brief Constructor sets attributes
         * @param[in] game Game object reference
         * @param[in] logger Optional reference to Logger object, default is nullptr
         */
        MenuOption(Game* game, Logger* logger = nullptr);
        virtual void execute() = 0;
        ~MenuOption() = default;
};

#endif // M_OPTION