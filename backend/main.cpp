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
    API myApi;
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

    gameApi.join();
    greenSock.join();
}

int main() {
    startThreads();
    
    return 0;
}