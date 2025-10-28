/**
 * @file GreenSock.h
 * @author Gerard Jordaan
 */
#ifndef WS_SOC
#define WS_SOC

#include <websocketpp/config/asio_no_tls.hpp>  
#include <websocketpp/server.hpp>
#include <iostream>
#include <string>
#include <mutex>

using server = websocketpp::server<websocketpp::config::asio>;

/**
 * @class Class representing a websocket, clients can connect to WS server, can send messages
 *  to clients
 */
class GreenSock {
    private:

        server s;
        websocketpp::connection_hdl* client_hdl;
        std::mutex mx;
        /**
         * @brief Defines behaviour for when client connection fails
         */
        void onFail();
        /**
         * @brief Behaviour on connection close. Frees client_hdl mem
         */
        void onClose();
        /**
         * @brief Behaviour for when client connection opens
         */
        void onOpen();
        /**
         * @brief Define what happens when client sends message, in our case we just echo the message
         *  since we only use the socket for unidirectional communication really
         */
        void onMessage();
    public:
        /**
         * @brief Inits log level (set to only log connects/disconnects). Inits behaviour by calling methods
         *  onFail, onClose, onOpen, onMessage. Inits server (asio), server needs to be initialized before it can be
         *  started
        */
        GreenSock();
        /**
         * @brief Destructor cleans up client handle if program terminates while connection still established
         */
        ~GreenSock();
        /**
         * @brief Sends unicode text to client
         */
        void sendMessage(std::string message);
        /**
         * @brief Starts socket, socket listens on port 8001 after executing this method.
         */
        void bootstrap();
};

#endif