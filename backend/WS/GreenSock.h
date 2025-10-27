#ifndef WS_SOC
#define WS_SOC

#include <websocketpp/config/asio_no_tls.hpp>  
#include <websocketpp/server.hpp>
#include <iostream>
#include <string>

using server = websocketpp::server<websocketpp::config::asio>;

class GreenSock {
    private:
        server s;
        websocketpp::connection_hdl* client_hdl;
        void onFail();
        void onClose();
        void onOpen();
        void onMessage();
    public:
        GreenSock();
        void sendMessage(std::string message);
        void bootstrap();
};

#endif