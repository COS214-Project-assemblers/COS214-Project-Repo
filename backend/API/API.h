/**
 * @file API.h
 * @brief Bootstrapper for public facing API
 * @author Gerard Jordaan
 */

#ifndef API_H
#define API_H

#include "APIController.h"
#include "APIComponent.h"
#include "../game/Game.h"

#include "oatpp/network/Server.hpp"
#include <iostream>

/**
 * @class API
 * @brief Bootstraps (starts) public facing API
 */
class API {
    private:
        Game* game;
    public:
        /**
         * @brief Conctructor that holds reference to Game object to execute API actions
         * @param[in] game reference to Game object to call methods on
         */
        API(Game* game);
        void run();
        void bootstrap();
};

#endif // API_H