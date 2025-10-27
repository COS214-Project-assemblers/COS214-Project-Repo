#include "WS.h"

#include <websocketpp/config/asio_no_tls.hpp>   // use asio.hpp without TLS
#include <websocketpp/server.hpp>
#include <iostream>

using server = websocketpp::server<websocketpp::config::asio>;

int startWS() {
  server s;
  s.init_asio();
  s.set_open_handler([&](websocketpp::connection_hdl hdl) {
    std::cout << "open\n";
  });
  s.set_fail_handler([&](websocketpp::connection_hdl) {
    std::cout << "fail\n";
  });
  s.set_close_handler([&](websocketpp::connection_hdl) {
    std::cout << "close\n";
  });
  s.set_message_handler([&](websocketpp::connection_hdl hdl, server::message_ptr msg) {
    s.send(hdl, msg->get_payload(), msg->get_opcode()); // echo
  });

  s.listen(8001);
  s.start_accept();
  s.run(); // single-threaded; for more threads, run io_service on N threads
}

void GreenSock::bootstrap() {
    startWS();
}