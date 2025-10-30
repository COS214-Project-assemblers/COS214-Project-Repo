/**
 * @file Plant.cpp
 * @brief Implements the functionality defined in the Plant class.
 */

#include "Plant.h"
#include "NotSellable.h"
#include "GreenhouseStaff.h"
#include "PlantHealth.h"
#include <sstream>
#include <nlohmann/json.hpp>
map<string, float> Plant::plantCosts =
{
    {"Rose", 10.0},
    {"Daisy", 5.0},
    {"Sunflower", 8.5},

    {"Cactus", 12.0},
    {"Aloe", 9.0},
    {"Jade", 7.5},

    {"Lemon", 15.0},
    {"Banana", 20.0},
    {"Apple", 25.0}
};

Plant::Plant(string category, string variety)
{
    this->plantCategory = category;
    this->plantVariety = variety;

    this->careType = "";
    this->plantState = new NotSellable();

    if(plantCosts[variety])
    {
        costPrice = plantCosts[variety];
    }
    else
    {
        costPrice = 10.00;
    }

    salePrice = costPrice * 1.5;

    // this->health = new Health() ; // concrete plants assign this uniquely
    this->decayIndex = 0        ;
    this->alive = true          ;
}

Plant::Plant(const Plant& original)
{
    this->plantCategory = original.plantCategory;
    this->plantVariety = original.plantVariety;
    this->costPrice = original.costPrice;
    this->salePrice = original.salePrice;

    this->plantState = new NotSellable();
    this->careType = original.careType;

    this->health = new Health() ; // NB You may not clone/copy mtx
    this->decayIndex = original.decayIndex ;
    this->alive = true ;
}

Plant::~Plant() {
    std::cout << "Plant::~Plant() " <<std::endl ;


    delete plantState;

    if (health){
        delete health ;
        health=NULL ;
    }
    stop() ;
    join() ;
}

string Plant::getPlantCategory()
{
    return plantCategory;
}

string Plant::getPlantVariety()
{
    return plantVariety;
}

float Plant::getCostPrice()
{
    return costPrice;
}

float Plant::getSalePrice()
{
    return salePrice;
}

void Plant::display()
{
    cout << plantCategory << " - " << plantVariety << ", Cost: R" << costPrice << ", Sale: R" << salePrice << endl;
}



PlantState *Plant::getState() {
    return plantState;
}

void Plant::attach(GreenhouseStaff *ob) {
    observerList.push_back(ob);
}

void Plant::detach(GreenhouseStaff *ob) {
    observerList.erase(std::remove(observerList.begin(), observerList.end(), ob), observerList.end());
}

void Plant::notify(std::string& careType) {
    for(GreenhouseStaff* observer : observerList) {
        observer->update(careType, this);
    }
}

std::string Plant::getCareType() {
    return careType;
}

void Plant::setState(PlantState *plantState_) {
    if(plantState != plantState_) {
        delete plantState;
        plantState = plantState_;
    }
}

void Plant::request() {
    plantState->handle(this);
}

Health* Plant::getHealth()  {
    return this->health ;
}

float Plant::healthScore() {
      return health->healthScore() ;
}

void Plant::start() {
    alive = true;
    thread = std::thread(&Plant::run, this);
}

void Plant::join() {
    std::cout << "[join] Stopping plant thread...\n";
    if (thread.joinable()) {
        thread.join();
    }
}

void Plant::stop() {
    std::cout << "[Info] Stopping plant thread...\n";
    alive = false;
}

void Plant::run() {
    std::cout << "[Debug] Plant thread started\n";

    while (alive && healthScore() > 0) {
        int waitTime = health->dist(health->rng);
        for (int i = 0; i < waitTime*10 && alive; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            if (i % 10 == 0) std::cout << "[Info] Sleeping... " << i/10 << "s passed\n";
        }
        std::lock_guard<std::mutex> lock(health->mtx);
        std::cout << "[Info] Running decay step, decayIndex=" << decayIndex << std::endl;

        health->decay(decayIndex) ;

        // Alerts - Plant is below minimum threshold - call the staff that need to handle
        if (health->water < 0.3f) {
            std::string careType = "water" ;    // I had to declare a variable like this
            this->notify(careType) ;            // then pass it in here because of the data type notify(std::string& careType)
            alert(careType, socket) ;
        }
        if (health->fertalizer < 0.3f) {
            std::string careType = "fertilizer" ;
            this->notify(careType) ;
            alert(careType, socket) ;
        }
        if (health->pruning < 0.3f) {
            std::string careType = "pruning" ;
            this->notify(careType) ;
            alert(careType, socket) ;
        }
        if (healthScore() <= 0) {
            this->alive = false ;
        }

        decayIndex = (decayIndex + 1) % 3;
        std::cout << "[Info] Moving to next decayIndex: " << decayIndex << std::endl;
        float currentHealth = health->healthScore() ;
        std::cout << "[State] Current health score: " << currentHealth << std::endl;
    }
    float currentHealth = health->healthScore()  ;
    std::cout << "[State] Current health score: " << currentHealth << std::endl;

    std::cout << "[Debug] Plant thread exiting\n";

}

boolean Plant::isSellabl() {
    if (health->isAlive() && (health->mature==3) ){
        return true ; 
    }
    return false ;
}

void Plant::setSocket(GreenSock* sock){
    this->socket = sock ; 
}

void Plant::alert(string& careType, GreenSock* sock) {
    if (!socket) {
        this->socket = sock ; 
    }
    nlohmann::json alert ;

        // Unique identifier (stringified memory address)
        std::ostringstream oss;
        oss << static_cast<const void*>(this);
        std::string plantId = oss.str();

        // Construct JSON alert payload
        alert = {
            {"plantId", "plantId"},
            {"plantCategory", getPlantCategory()},
            {"plantVariety", getPlantVariety()},
            {"healthScore", health->healthScore()},
            {"waterScore", heath->getWater()},
            {"pruningScore", heath->healthPrune()},
            {"fertilizerScore", heath->getFertilizer()},
            {"sellable", health->isSellabl()()},
            {"died", health->isAlive()}
        };

        // Convert JSON to string and send via WebSocket

        std::string jsonString = alert.dump();
        std::cout << jsonString << std::endl;

        socket->sendMessage( jsonString );

}

/* 
.then(() => addDBRecord({ 
      plantId: "3f6a2d2b-7a5e-4f06-9b4f-2f8e6a2c9b8d",
      plantCategory: "succulent",
      plantVariety: "cactus",
      healthScore: 0.5,
      waterScore: 10,
      pruningScore: 10,
      fertilizerScore: 10,
      sellable: false,
      died: false
    }))
*/
