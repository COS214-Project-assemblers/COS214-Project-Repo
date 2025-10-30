/**
 * @file Plant.cpp
 * @brief Implements the functionality defined in the Plant class.
 */

#include "Plant.h"
#include "NotSellable.h"
#include "GreenhouseStaff.h"
#include "PlantHealth.h"

Plant::Plant(string category, string variety,string difficulty)
{
    // Assign ID to plant
    this->plantCategory = category;
    this->plantVariety = variety;
    this->difficulty=difficulty;

    this->careType = "";
    this->plantState = new NotSellable();
    
    // Game needs to be initialized (prices fetched from JSON) before
    // plant costs can be set. If game not initialized, plant costs not set.
    if(!plantCosts.empty() && plantCosts[variety].size() == 2)
    {
        costPrice = plantCosts[variety][0];
        salePrice = plantCosts[variety][1];
    }
    else
    {
        costPrice = 10.00;
    }

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
    this->difficulty=original.difficulty;
    this->acceptable=original.acceptable;
    this->returnable=original.returnable;

    this->plantState = new NotSellable();
    this->careType = original.careType;

    this->health = new Health() ; // NB You may not clone/copy mtx
    this->decayIndex = original.decayIndex ;
    this->alive = true ;

    generateId();
    if (logger) {
        logger->newLog("Created plant " + id);
    }
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

string Plant::getCareLevel()
{
    return careLevel;
}

string Plant::getPlantCategory()
{
    return plantCategory;
}

string Plant::getPlantVariety()
{
    return plantVariety;
}

int Plant::getCostPrice()
{
    return costPrice;
}

float Plant::getSalePrice()
{
    return salePrice;
}

std::string Plant::getDifficulty()
{
    return difficulty;
}

void Plant::display()
{
    cout << plantCategory << " - " << plantVariety << ", Cost: R" << costPrice << ", Sale: R" << salePrice <<", Difficulty: "<<difficulty<< endl;
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
        }
        if (health->fertalizer < 0.3f) {
            std::string careType = "fertilizer" ;
            this->notify(careType) ;
        }
        if (health->pruning < 0.3f) {
            std::string careType = "pruning" ;
            this->notify(careType) ;
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
}

void Plant::generateId() {
    // Static + thread local ensures there is only 1 random num gen 
    if (id == "") {
        static thread_local boost::uuids::random_generator gen;
        this->id = to_string(gen());
    }
}

string Plant::getId() {
    return id;
}
void Plant::setReturnable(bool returnable){
    this->returnable=returnable;
}

bool Plant::isReturnable(){
    return this->returnable;
}

void Plant::setAcceptable(bool acceptable)
{
    this->acceptable = acceptable;
}

bool Plant::isAcceptable()
{
    return acceptable;
}

void Plant::setPlantCosts(map<string, vector<int>> plantCosts)
{
    Plant::plantCosts = plantCosts;
}

void Plant::stubPlant() {
    plantCosts = {};
    logger = nullptr;
}

map<string, vector<int>> Plant::getPlantCosts() {
    return plantCosts;
}

void Plant::setLogger(Logger* passedLogger) {
    logger = passedLogger;
}

void Plant::newPlantLog(string message) {
    if (!(id == "")) {
        message = id + message;
    }
    if (logger != nullptr) {
        logger->newLog(message);
    }
} 