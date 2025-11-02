#include "GreenSock.h"

GreenSock::GreenSock() {

  std::cout << "Initalising green sock\n" ; 
  // s.clear_access_channels(websocketpp::log::alevel::all);
  // s.set_access_channels(websocketpp::log::alevel::connect);
  // s.set_access_channels(websocketpp::log::alevel::disconnect);
  s.init_asio();
  onMessage();
  onOpen();
  onFail();
  onClose();
}

void GreenSock::onOpen() {
  s.set_open_handler([&](websocketpp::connection_hdl hdl) {
    std::cout << "open\n";
    client_hdl = new websocketpp::connection_hdl(hdl);
  });
}

void GreenSock::onMessage() {
  s.set_message_handler([&](websocketpp::connection_hdl hdl, server::message_ptr msg) {
    // sendMessage(msg->get_payload()); // echo
    std::cout << msg->get_payload() << std::endl;
  });
}

void GreenSock::onClose() {
  s.set_close_handler([&](websocketpp::connection_hdl) {
    if (client_hdl) {
      delete client_hdl;
      client_hdl = NULL;
    }
  });
}

void GreenSock::onFail() {
  s.set_fail_handler([&](websocketpp::connection_hdl) {
    std::cout << "fail\n";
  });
}

void GreenSock::sendMessage(std::string message) {
    
    std::lock_guard<std::mutex> lock(mx); 

    if (client_hdl) {

      websocketpp::connection_hdl hdl_copy = *client_hdl; 
      std::string msg_copy = message;

      s.get_io_service().post([this, hdl_copy, msg_copy]() {

          websocketpp::lib::error_code ec;  
          this->s.send(hdl_copy, msg_copy, websocketpp::frame::opcode::text, ec); 
          if (ec == websocketpp::error::bad_connection) {
            std::cout << " \n\t BAD CONNECTION \n" <<  std::endl ;
            // Do nothing
          }
      });
    } else {
      std::cout << "Client not yet connected\n";
    }
}


void GreenSock::bootstrap() {
    std::cout << "\n[GreenSock] Bootstrapping WebSocket server..." << std::endl;

    try {
        s.listen(8001);
        std::cout << "[GreenSock] Listening on port 8001 " << std::endl;

        s.start_accept();
        std::cout << "[GreenSock] Waiting for incoming connections..." << std::endl;

        s.run();
        std::cout << "[GreenSock] Server event loop running." << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "[GreenSock] Failed to start server: " << e.what() << std::endl;
    }
}


GreenSock::~GreenSock() {
  if (client_hdl != nullptr) {
    delete client_hdl;
  }
}