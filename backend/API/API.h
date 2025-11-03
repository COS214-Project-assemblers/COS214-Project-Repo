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
 * @brief Bootstraps (starts) and manages public facing API server
 * @details Main application class that initializes Oat++ environment, 
 * configures components, and manages the game lifecycle. Provides access
 * to game functionality for controllers through friend class relationship.
 */
class API {
    private:
        /**
         * @brief Pointer to current game instance
         */
        Game* game = nullptr;
    public:

        /**
         * @brief Declare APIController as friend class
         * @details Allows APIController to access private member variables 
         * like the "game" member variable. This ensures extensibility - 
         * client interacts with API, API with APIController. If APIController 
         * needs more context, client can pass to API to store in state, 
         * and APIController has access to API state.
         */
        friend class APIController;

        /**
         * @brief Bootstrap API server components and start server
         * @details Initializes Oat++ components, sets up HTTP router, 
         * registers controllers, and starts TCP server on port 8000
         */
        void bootstrap();

        /**
         * @brief Main entry point to run the API server
         * @details Calls bootstrap() and handles Oat++ environment initialization and cleanup
         */
        void run();

        /**
         * @brief Cleans up and exits the current game
         * @details Deletes the current game instance if it exists
         */
        void exitGame();

        /**
         * @brief Sets WebSocket connection for real-time communication
         * @param sock Pointer to GreenSock WebSocket instance
         */
        void setSocket(GreenSock* socket);

         /**
         * @brief Sets the game instance for API to manage
         * @param game Pointer to Game instance
         */
        void setGame(Game* game);
};

#endif