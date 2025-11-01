/**
 * @file API.h
 * @brief Bootstrapper for public facing API
 * @author Gerard Jordaan
 */

#ifndef API_H
#define API_H

#include "APIComponent.h"
#include "Game.h"
#include "GreenSock.h"
#include "oatpp/network/Server.hpp"
#include <iostream>

class APIController;

/**
 * @class API
 * @brief Bootstraps (starts) public facing API
 */
class API {
    private:
        Game* game = nullptr;
    public:

        /**
         * @brief Bootstrap (https://en.wikipedia.org/wiki/Bootstrapping) API server
         */
        void bootstrap();
        /**
         * @brief Allows the client to start API server, calls bootstrapper
         */
        void run();
        /**
         * @brief Declare APIController as friend class of API such that APIController can have access
         *  to private member variables like the "game" member variable.
         *  This is done to ensure extensibility, client interacts with API, API with APIController, if
         *  ever APIController needs more context client can pass to API to store in state, APIController
         *  has access to API state.
         */
        friend class APIController;

        /**
         * @brief deletes current game member
         */
        void exitGame();

        void setSocket(GreenSock* socket);

        void setGame(Game* game);
};

#endif // API_H