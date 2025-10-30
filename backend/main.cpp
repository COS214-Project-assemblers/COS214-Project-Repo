#include "API.h"
#include "Game.h"
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include "GreenSock.h"
#include "Plant.h"
#include "PlantHealth.h"
#include <random>


GreenSock greenSock = GreenSock();
std::random_device rd; 
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(1000, 3000);

void startGameApi() {
    char* gameConfigPath = getenv("GAME_CONFIG_PATH");
    if (gameConfigPath == nullptr) {
        std::cout << "GAME_CONFIG_PATH environment variable not set, exiting..." << std::endl;
        exit(EXIT_FAILURE);
    }
    API myApi = API(new Game(gameConfigPath));
    myApi.bootstrap();
}

void startGreenSock() {
    greenSock.bootstrap();
}

void testGreenSock() {
    while (true) {
        greenSock.sendMessage("{\"message\": \"test message\"}");
        std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen)));
    }
}

void startThreads() {
    std::thread gameApi(startGameApi);
    std::thread greenSock(startGreenSock);

    // Plant* myPlant = new Succulent("Aloe")      ;
    // myPlant->setSocket(&greenSock)              ;
    // std::string careType = "TESTING" ;
    // myPlant->alert(string& careType, greenSock)    ; 

    // delete myPlant;

    gameApi.join();
    greenSock.join();
}
/*
void succulentDecayAndAlert() {
    std::cout << "[System] Bootstrapping GreenSock...\n";
    std::thread socketThread([]() {
        greenSock.bootstrap(); // start websocket server on port 8001
    });

    std::thread gameApi(startGameApi);
    std::thread greenSock(startGreenSock);

    // Give the socket some time to start listening
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "[System] Creating test plant...\n";
    Plant* myPlant = new Succulent("cactus");

    // Link the websocket to the plant
    myPlant->setSocket(&greenSock);

    // Start the plant’s decay process
    std::cout << "[System] Starting plant thread...\n";
    myPlant->start();

    // Let it decay for a while
    std::cout << "[System] Letting plant decay for 10 seconds...\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout << "[System] Stopping plant thread...\n";
    myPlant->stop();
    myPlant->join();

    std::cout << "[System] Checking final health score...\n";
    float finalHealth = myPlant->healthScore();
    std::cout << "[Result] Final health: " << finalHealth << std::endl;

    delete myPlant;

    std::cout << "[System] Shutting down GreenSock thread...\n";
    // We’re not calling s.stop_listening() in GreenSock yet, so just join
    socketThread.join();

    std::cout << "[System] Test complete.\n";

    gameApi.join();
    greenSock.join();
}
*/

int main() {
    startThreads();
    // succulentDecayAndAlert() ; 
    return 0;
}