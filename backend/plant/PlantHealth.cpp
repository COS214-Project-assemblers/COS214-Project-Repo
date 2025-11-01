#include "PlantHealth.h"

Health::Health(float water, float fertalizer, float pruning, int mature){
    this->water = water ;
    this->fertalizer = fertalizer ;
    this->pruning = pruning ;
    this->mature = mature ;
    this->originalHeathTotal = water + fertalizer + pruning ; 

    this->rng = std::mt19937(std::random_device{}()) ;
    this->dist = std::uniform_int_distribution<int>(3, 7);
}

Health::~Health() {
    // no dynamic memory - nothing to delete
}

void Health::handleWater() {
    std::lock_guard<std::mutex> lock(mtx);
    float needed = (1.0f - water);
    std::cout << "Amount Needed " << needed << std::endl;
    _setWaterUnlocked(water + needed);
}

void Health::handleFertilizer() {
    std::lock_guard<std::mutex> lock(mtx);
    float needed = (1.0f - fertalizer);
    std::cout << "Amount Needed " << needed << std::endl;
    _setFertilizerUnlocked(fertalizer + needed);
}

void Health::handlePruning() {
    std::lock_guard<std::mutex> lock(mtx);
    float needed = (1.0f - pruning);
    std::cout << "Amount Needed " << needed << std::endl;
    _setPruningUnlocked(pruning + needed);
    mature++;
}


Health* Health::clone(){
    return new Health() ;

}


float Health::healthScore() {
    std::lock_guard<std::mutex> lock(mtx);
    return (this->water + this->fertalizer  + this->pruning)/originalHeathTotal ;
}


float Health::getWater() {
    std::lock_guard<std::mutex> lock(mtx);
    return this->water ; 
}
float Health::getFertilizer() {
    std::lock_guard<std::mutex> lock(mtx);
    return this->fertalizer ; 
}

float Health::healthPrune(){
    std::lock_guard<std::mutex> lock(mtx);
    return this->pruning ; 
}

 int Health::getMaturity() {
    std::lock_guard<std::mutex> lock(mtx);
    return this->mature;
 ;

 }

 bool Health::isDead() {
    std::lock_guard<std::mutex> lock(mtx);
    return (healthScore() < 0.3) ; 
 }


void Health::decay(int decayIndex) {
    std::lock_guard<std::mutex> lock(mtx);
    switch (decayIndex) {
        case 0:
            std::cout << "\t[Decay] Before water decay: " << water << std::endl;
            _setWaterUnlocked(std::max(0.0f, water - 0.5f));
            std::cout << "\t[Decay] After water decay: " << water << std::endl;
            break;
        case 1:
            std::cout << "\t[Decay] Before fertilizer decay: " << fertalizer << std::endl;
            _setFertilizerUnlocked(std::max(0.0f, fertalizer - 0.5f));
            std::cout << "\t[Decay] After fertilizer decay: " << fertalizer << std::endl;
            break;
        case 2:
            std::cout << "\t[Decay] Before pruning decay: " << pruning << std::endl;
            _setPruningUnlocked(std::max(0.0f, pruning - 0.5f));
            std::cout << "\t[Decay] After pruning decay: " << pruning << std::endl;
            break;
    }
}


/*
A Note on std::clamp:
    Set water to w, but if someone tries to set it below 0 or above 1, stick to the nearest valid bound.
    
    this is a function of :

    if (w < 0.0f) water = 0.0f;
    else if (w > 1.0f) water = 1.0f;
    else water = w;
*/

// public thread-safe versions
void Health::setWater(float w) {
    std::lock_guard<std::mutex> lock(mtx);
    _setWaterUnlocked(std::clamp(w, 0.0f, 1.0f));
}

void Health::setFertilizer(float f) {
    std::lock_guard<std::mutex> lock(mtx);
    _setFertilizerUnlocked(std::clamp(f, 0.0f, 1.0f));
}

void Health::setPruning(float p) {
    std::lock_guard<std::mutex> lock(mtx);
    _setPruningUnlocked(std::clamp(p, 0.0f, 1.0f));
}

// private versions (no lock — only for internal use)
void Health::_setWaterUnlocked(float w) { water = w; }
void Health::_setFertilizerUnlocked(float f) { fertalizer = f; }
void Health::_setPruningUnlocked(float p) { pruning = p; }

