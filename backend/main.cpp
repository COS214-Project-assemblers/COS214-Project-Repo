#include "API.h"
#include "Game.h"
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include "GreenSock.h"
#include "Plant.h"
#include "Succulent.h"
#include "Flower.h"
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

    std::thread gameApiThread(startGameApi);
    std::thread greenSockThread(startGreenSock);

    std::cout << "Testing plant thread dynamic behavior" <<std::endl ; 
        Plant* myPlant = new Succulent("Aloe");
        while(myPlant->healthScore() > 0){
            myPlant->setSocket(&greenSock);
            std::string careType = "TESTING";
            myPlant->alert(careType, &greenSock);
            std::this_thread::sleep_for(std::chrono::milliseconds(dist(gen)));
        }
        delete myPlant ; 


    gameApiThread.join();
    greenSockThread.join();

}

void testingPlantRun() {

    std::thread gameApiThread(startGameApi);
    std::thread greenSockThread(startGreenSock);

    std::cout << "Testing plant thread dynamic behavior" <<std::endl ; 
        Plant* myPlant = new Succulent("Aloe");
        myPlant->start() ;
    gameApiThread.join();
    greenSockThread.join();
}


void startThreads() {
    std::thread gameApiThread(startGameApi);
    std::thread greenSockThread(startGreenSock);
    // std::thread greenSockThread2(testingRandomisedThreads);



    gameApiThread.join();
    greenSockThread.join();
    // greenSockThread2.join();
}


void testOneThread(){
    std::thread greenSockThread(startGreenSock);
    Plant* myPlant = new Succulent("Aloe");
    myPlant->setSocket(&greenSock) ; 

    // float initialScore = myPlant->healthScore();

    myPlant->start();
    std::this_thread::sleep_for(std::chrono::seconds(180)); // let decay happen
    // myPlant->stop(); // force the thread to stop
    // myPlant->join();

    // float laterScore = myPlant->healthScore();

    delete myPlant;
    greenSockThread.join();
}

void testNthreads() {
    std::thread greenSockThread(startGreenSock);
    Plant* Aloe = new Succulent("Aloe");
    Aloe->setSocket(&greenSock) ; 

    Plant* rose = new Flower("rose");
    rose->setSocket(&greenSock) ; 
    // float initialScore = myPlant->healthScore();

    Aloe->start();
    rose->start() ; 
    std::this_thread::sleep_for(std::chrono::seconds(180)); // let decay happen
    // myPlant->stop(); // force the thread to stop
    // myPlant->join();

    // float laterScore = myPlant->healthScore();

    delete Aloe;
    delete rose ;
    greenSockThread.join();
}


int main() {
    // testingRandomisedThreads() ; 
    // testingPlantRun() ; 
    // tes() ; 
    testNthreads() ; 
    return 0;
}