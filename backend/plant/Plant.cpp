/**
 * @file Plant.cpp
 * @brief Implements the functionality defined in the Plant class.
 */

#include "Plant.h"
#include "NotSellable.h"
#include "GreenhouseStaff.h"
#include "PlantHealth.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define CYAN    "\033[36m"

void Plant::plantDetail(){
    std::cout << "Plant Variety " << this->getPlantVariety() << std::endl ; 
    std::cout << "Plant Id " << this->getId() << std::endl ; 
    std::cout << "Plant memory Location " << this << std::endl ; 
}
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
        logger->newLog("Created [" + getPlantCategory() + "] " + getPlantVariety() + " with unique ID: " + id);
    }
}

Plant::~Plant() {
    std::cout << CYAN
              << "\n\tPlant::~Plant() - deleting plant id: "
              << this->getPlantVariety() << this->getId()
              << RESET << std::endl;

    stop();  // Tell thread to stop (atomic or locked)
    join();  // Wait for it to finish before deleting anything

    // Now it's 100% dead — we can safely clean up
    std::lock_guard<std::mutex> ptrLock(healthPtrMutex);
    if (health) {
        std::lock_guard<std::mutex> dataLock(health->mtx);
        delete health;
        health = nullptr;
    }

    if (plantState) {
        delete plantState;
        plantState = nullptr;
    }
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

// Plant.h (or Plant.cpp; put template definition in header or inlined)
template <typename Func>
void Plant::withHealthLocked(Func func) {
    // Fast exit if we're already shutting down (avoid unnecessary locking)
    if (!alive.load()) return;

    // Protect the pointer itself so it cannot be deleted or changed while we proceed
    std::lock_guard<std::mutex> ptrLock(healthPtrMutex);

    // Re-check after acquiring the pointer lock: shutdown may have started
    if (!alive.load() || health == nullptr) return;

    // Now protect the internal data of the Health object
    std::lock_guard<std::mutex> dataLock(health->mtx);

    // Execute the user-provided operation on the Health object while both locks are held
    func(*health);
}


void Plant::start() {
    alive = true;
    thread = std::thread(&Plant::run, this);
}

void Plant::join() {
    std::cout << GREEN<< "\t[Join] Stopping plant thread..." << this->getPlantVariety() << this << RESET << std::endl ;

    if (thread.joinable()) {
        std::cout << GREEN<< "\t[Join] (thread.joinable() == TRUE) therefore joining " << this->getPlantVariety() << this << RESET << std::endl ;
        thread.join();
    }
}

void Plant::stop() {
    std::cout << GREEN<< "\t[Info] Stopping plant thread..." << this->getPlantVariety() << this  << RESET << std::endl ;
    alive.store(false);
}

/*
void Plant::run() {
    std::cout << YELLOW << "\n\t[Debug] Plant thread started, details:\n" 
                        << "\n\tVariety: "<< this->getPlantVariety() 
                        << "\n\tMemory Address "<< this  << RESET << std::endl;

    while (alive.load()) {
        int waitTime = health->dist(health->rng);
        for (int i = 0; i < waitTime*10 && alive; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            // if (i % 10 == 0) std::cout << "[Info] Sleeping... " << i/10 << "s passed\n";
        }
        std::lock_guard<std::mutex> lock(health->mtx);
        std::cout << "it[Info] Running decay step for " << this->getPlantVariety() <<" ["<<this << "], decayIndex=" << decayIndex << std::endl;

        health->decay(decayIndex) ;

        // Alerts - Plant is below minimum threshold - call the staff that need to handle
        if (health->water < 0.4f) {
            std::cout << "LOW WATER: (health->water < 0.3f)" <<std::endl ; 
            std::string careType = "water" ;    // I had to declare a variable like this
            this->notify(careType) ;            // then pass it in here because of the data type notify(std::string& careType)
            alert(careType, socket) ;
        }
        if (health->fertalizer < 0.4f) {
            std::cout << "LOW FERTILIZER: (health->water < 0.3f)" <<std::endl ; 
            std::string careType = "fertilizer" ;
            this->notify(careType) ;
            alert(careType, socket) ;
        }
        if (health->pruning < 0.4f) {
            std::cout << "LOW PRUNING: (health->water < 0.3f)" <<std::endl ; 
            std::string careType = "pruning" ;
            this->notify(careType) ;
            alert(careType, socket) ;
        }
        if (healthScore() < 0.0001f) {
            std::cout <<"DEAD This current Plants Health Score is < 0.0001 DEAD"<< std::endl ; 
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
*/

void Plant::run() {
    std::cout << YELLOW << "\n\t[Debug] Plant thread started, details:\n"
              << "\n\tVariety: " << getPlantVariety()
              << "\n\tMemory Address: " << this << RESET << std::endl;

    while (alive.load()) {
        // 1) Get waitTime safely from health (under lock)
        int waitTime = 1;
        withHealthLocked([&](Health& h) {
            waitTime = h.dist(h.rng);
        });

        // 2) Sleep but check alive each iteration (no health access here)
        for (int i = 0; i < waitTime * 10 && alive.load(); ++i)
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // 3) Do decay + collect any alert-worthy info inside one locked lambda
        //    But DO NOT call notify()/alert() or socket->send while under the lock.
        struct AlertSnapshot {
            bool needWater = false;
            bool needFertilizer = false;
            bool needPruning = false;
            float score = 0.0f;
            float water = 0.0f;
            float fertilizer = 0.0f;
            float pruning = 0.0f;
            bool dead = false;
        } snap;

        /*=======HEALTH IS LOCKED===========*/
        withHealthLocked([&](Health& h) {
            std::cout << "it[Info] Running decay step for " << getPlantVariety()
                      << " [" << this << "], decayIndex=" << decayIndex << std::endl;

            h.decay(decayIndex);

            snap.water = h.getWater();
            snap.fertilizer = h.getFertilizer();
            snap.pruning = h.healthPrune();
            snap.score = h.healthScore();
            snap.dead = h.isDead();

            snap.needWater = (snap.water < 0.4f);
            snap.needFertilizer = (snap.fertilizer < 0.4f);
            snap.needPruning = (snap.pruning < 0.4f);

            if (snap.score < 0.0001f) {
                // flag death; modify alive under the pointer lock or outside — both ok,
                // but store to atomic to inform loop.
                alive.store(false);
            }
        });
        /*=======HEALTH IS UNNLOCKED===========*/

        // 4) After releasing the locks, do notifications / socket I/O based on snapshot
        if (snap.needWater) {
            std::string careType = "water";
            notify(careType);
            alert(careType, socket); // alert will read health snapshot itself (see below)
        }
        if (snap.needFertilizer) {
            std::string careType = "fertilizer";
            notify(careType);
            alert(careType, socket);
        }
        if (snap.needPruning) {
            std::string careType = "pruning";
            notify(careType);
            alert(careType, socket);
        }

        // 5) advance decay index and optionally print last-known health (we can read again)
        decayIndex = (decayIndex + 1) % 3;
        std::cout << "[Info] Moving to next decayIndex: " << decayIndex << std::endl;

        // safe read for logging current health:
        float currentHealth = 0.0f;
        withHealthLocked([&](Health& h){ currentHealth = h.healthScore(); });
        std::cout << "[State] Current health score: " << currentHealth << std::endl;
    }

    // Final safe read + exit message
    float finalHealth = 0.0f;
    withHealthLocked([&](Health& h){ finalHealth = h.healthScore(); });
    std::cout << "[State] Final health score: " << finalHealth << std::endl;
    std::cout << "[Debug] Plant thread exiting\n";
}


bool Plant::isSellable() {
    bool sellable = false;
    withHealthLocked([&](Health& h) {
        sellable = (!h.isDead() && (h.getMaturity() > 2));
    });
    return sellable;
}


void Plant::setSocket(GreenSock* sock){
    this->socket = sock ; 
}

/*
void Plant::alert(string& careType, GreenSock* sock) {
    if (!socket) {
        this->socket = sock ; 
    }
    nlohmann::json alert ;
    std::cout << "void Plant::alert(string& " << careType << "!!!, GreenSock* sock)" << std::endl ; 

        // Unique identifier (stringified memory address)
        std::ostringstream oss;
        oss << static_cast<const void*>(this);
        std::string plantId = oss.str();

        // Construct JSON alert payload
        alert = {
            {"plantId", getId()},
            {"plantCategory", getPlantCategory()},
            {"plantVariety", getPlantVariety()},
            {"healthScore", health->healthScore()},
            {"waterScore", health->getWater()},
            {"pruningScore", health->healthPrune()},
            {"fertilizerScore", health->getFertilizer()},
            {"sellable", isSellable()},
            {"died", health->isDead()}
        };

        // Convert JSON to string and send via WebSocket

        std::string jsonString = alert.dump();
        std::cout << "\t Sedning to greenSock: ===> " << jsonString << std::endl;

        socket->sendMessage( jsonString );

}
*/

void Plant::alert(std::string& careType, GreenSock* sock) {
    // Take a snapshot of necessary fields under lock
    struct HealthSnapshot {
        float healthScore = 0.0f;
        float water = 0.0f;
        float pruning = 0.0f;
        float fertilizer = 0.0f;
        bool died = false;
        int maturity = 0;
    } s;

    withHealthLocked([&](Health& h) {
        s.healthScore = h.healthScore();
        s.water = h.getWater();
        s.pruning = h.healthPrune();
        s.fertilizer = h.getFertilizer();
        s.died = h.isDead();
        s.maturity = h.getMaturity();
    });

    // Build JSON and send outside the lock
    nlohmann::json alert;
    alert = {
        {"plantId", getId()},
        {"plantCategory", getPlantCategory()},
        {"plantVariety", getPlantVariety()},
        {"healthScore", s.healthScore},
        {"waterScore", s.water},
        {"pruningScore", s.pruning},
        {"fertilizerScore", s.fertilizer},
        {"sellable", (!s.died && s.maturity > 2)},
        {"died", s.died}
    };

    std::string jsonString = alert.dump();
    std::cout << "\t Sending to greenSock: ===> " << jsonString << std::endl;

    // socket should be valid; if not, set it (minimal check)
    if (!socket && sock) socket = sock;
    if (socket) socket->sendMessage(jsonString);
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
