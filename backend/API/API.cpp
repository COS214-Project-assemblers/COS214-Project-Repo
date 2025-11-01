#include "API.h"
#include "APIController.h"


void API::exitGame()
{
  if (game != nullptr) { // Sanity check probs would not happen
    delete game;
  }
}

void API::setSocket(GreenSock* sock)
{
  game->setSocket(sock);
  cout << "Game socket set" << endl;
}

// Inspiration from https://github.com/oatpp/oatpp-starter/blob/master/src/App.cpp
void API::bootstrap()
{
    APIComponent components;

    /* Get router component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    /* Create MyController and add all of its endpoints to router */
    router->addController(APIController::createShared(*this));

    /* Get connection handler component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

    /* Get connection provider component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

    /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    /* Print info about server port */
    OATPP_LOGi("MyApp", "Server running on port {}", connectionProvider->getProperty("port").toString());

    /* Run server */
    server.run();
}

void API::run() {
    oatpp::Environment::init();

  bootstrap();
  
  /* Print how much objects were created during app running, and what have left-probably leaked */
  /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::Environment::getObjectsCreated() << "\n\n";
  
  oatpp::Environment::destroy();
}

void API::setGame(Game* game) {
  if (this->game == nullptr) {
    this->game = game;
  }
}