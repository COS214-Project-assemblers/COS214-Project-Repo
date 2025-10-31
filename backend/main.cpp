#include "API.h"
#include "Game.h"
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include "GreenSock.h"
#include "Plant.h"
#include "Succulent.h"
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
        Plant* myPlant = new Succulent("Aloe");
        myPlant->setSocket(&greenSock);

        std::string careType = "TESTING";
        myPlant->alert(careType, &greenSock);
        std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen)));
        delete myPlant ; 
    }
    
}

void testingRandomisedThreads() {
    std::cout << "Testing plant thread dynamic behavior" <<std::endl ; 
        Plant* myPlant = new Succulent("Aloe");
        while(myPlant->healthScore() > 0){
            myPlant->setSocket(&greenSock);
            std::string careType = "TESTING";
            myPlant->alert(careType, &greenSock);
            std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen)));
        }
        delete myPlant ; 

}


void startThreads() {
    std::thread gameApiThread(startGameApi);
    // std::thread greenSockThread(testGreenSock);
    // std::thread greenSockThread2(testingRandomisedThreads);



    gameApiThread.join();
    // greenSockThread.join();
    // greenSockThread2.join();
}

void startSocket() {
    startGreenSock()  ;
    greenSock.sendMessage("Test Message") ; 

}



int main() {
    // startThreads();
    // succulentDecayAndAlert() ; 
    startSocket() ; 
    return 0;
}