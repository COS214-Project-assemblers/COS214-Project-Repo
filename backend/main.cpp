#include "API.h"
#include "Game.h"
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include "GreenSock.h"
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
    std::thread testSocket1(testGreenSock);
    std::thread testSocket2(testGreenSock);

    gameApi.join();
    testSocket1.join();
    testSocket2.join();
    greenSock.join();
}

int main() {
    startThreads();
    
    return 0;
}