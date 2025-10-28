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

using server = websocketpp::server<websocketpp::config::asio>;

/**
 * @class Class representing a websocket, clients can connect to WS server, can send messages
 *  to clients
 */
class GreenSock {
    private:
        server s;
        websocketpp::connection_hdl* client_hdl;
        /**
         * @brief Defines behaviour for when client connection fails
         */
        void onFail();
        /**
         * 
         */
        void onClose();
        void onOpen();
        void onMessage();
    public:
        GreenSock();
        void sendMessage(std::string message);
        void bootstrap();
};

#endif