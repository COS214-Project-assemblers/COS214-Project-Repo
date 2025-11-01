#include "API.h"
#include "Game.h"
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include "GreenSock.h"

#include "Plant.h"
#include "PlantCreator.h"


#include "Succulent.h"
#include "SucculentCreator.h"

#include "Flower.h"
#include "FlowerCreator.h"

#include "Tree.h"
#include "TreeCreator.h"

#include "PlantHealth.h"


#include "Greenhouse.h"
#include <random>




GreenSock greenSock = GreenSock();
std::random_device rd; 
std::mt19937 gen(rd());
std::uniform_int_distribution<> dist(1000, 3000);

void startApi(API api) {
    api.bootstrap();
}

void startSocket() {
    greenSock.bootstrap();
}

void startGameApi() {
    char* gameConfigPath = getenv("GAME_CONFIG_PATH");
    if (gameConfigPath == nullptr) {
        std::cout << "GAME_CONFIG_PATH environment variable not set, exiting..." << std::endl;
        exit(EXIT_FAILURE);
    }
    API myApi;
    myApi.setSocket(&greenSock);
    
    std::thread apiThread(startApi, myApi);
    // std::thread sockThread(startSocket);

    apiThread.join();
    // sockThread.join();
}



void startGreenSock() {
    greenSock.bootstrap();
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
    Plant* myPlant = new Succulent("Aloe", "Easy");
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
    Plant* Aloe = new Succulent("Aloe", "Easy");
    Aloe->setSocket(&greenSock) ; 

    Plant* rose = new Flower("rose", "Easy");
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

void prt(std::string debugging){
    std::cout << debugging <<std::endl ;

}
void testGreenhouseFlow()   {
    std::thread greenSockThread(startGreenSock);
    prt("void testGreenhouseFlow() ") ;

    // Make a Greenhouse where plants can be added to
    Greenhouse* greenhouse = new Greenhouse(&greenSock); 
    // greenhouse->setSocket(&greenSock) ; 
    Plant::stubPlant();

    // Make plant factories And then Plants
        // succulent - aloe        
        SucculentCreator succulentCreator;
        succulentCreator.makePlant("Cactus");
        Plant* succulent = succulentCreator.getPlant();
        Plant* clonedSucculent = succulent->clone();


        // flower - rose
        FlowerCreator flowerCreator;
        flowerCreator.makePlant("Rose");
        Plant* flower = flowerCreator.getPlant();
        Plant* clonedFlower = flower->clone();


        // tree - lemon
        TreeCreator treeCreator;
        treeCreator.makePlant("Lemon");
        Plant* tree = treeCreator.getPlant();
        Plant* clonedTree = tree->clone();

        


    // Add the plants to the Greenhouse (This is where the threads will be started)
    prt(" Adding Plants to the green House:") ;
    greenhouse->addPlant(clonedSucculent) ; 
    greenhouse->addPlant(clonedFlower) ; 
    greenhouse->addPlant(clonedTree) ; 

    std::this_thread::sleep_for(std::chrono::seconds(180)); 
    prt(" Deleting the greenhouse: ") ;
    delete greenhouse ; 

    // delete plants that were used to clone 
    delete succulent ; 
    delete flower ; 
    delete tree ; 
    greenSockThread.join();
}



int main() {
    // testingRandomisedThreads() ; 
    // testingPlantRun() ; 
    // tes() ; 
    // testNthreads() ; 
    // testGreenhouseFlow() ; 
    // startGameApi();
    startGameApi();
    return 0;
}