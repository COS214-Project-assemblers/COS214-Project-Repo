#include "GreenSock.h"

GreenSock::GreenSock() {
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
    sendMessage(msg->get_payload()); // echo
  });
}

void GreenSock::onClose() {
  s.set_close_handler([&](websocketpp::connection_hdl) {
    std::cout << "close\n";
  });
}

void GreenSock::onFail() {
  s.set_fail_handler([&](websocketpp::connection_hdl) {
    std::cout << "fail\n";
  });
}

void GreenSock::sendMessage(std::string message) {
  if (client_hdl) {
    websocketpp::connection_hdl hdl_copy = *client_hdl;
    std::string msg_copy = message;
    s.get_io_service().post([this, hdl_copy, msg_copy]() {
        this->s.send(hdl_copy, msg_copy, websocketpp::frame::opcode::text);
    });
  } else {
    std::cout << "Client not yet connected\n";
  }
}

void GreenSock::bootstrap() {
    s.listen(8001);
    s.start_accept();
    s.run();
}