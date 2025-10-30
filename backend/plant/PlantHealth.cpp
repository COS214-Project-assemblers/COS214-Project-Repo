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

void Health::handleWater(){
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Amount Needed " << (1.0 - this->water) << std::endl ;
    this->water += (1.0 - this->water) ;

}

void Health::handleFertilizer(){
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Amount Needed " << (1.0 - this->fertalizer) << std::endl ;
    this->water += (1.0 - this->fertalizer) ;
}

void Health::handlePruning(){
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Amount Needed " << (1.0 - this->pruning) << std::endl ;
    this->water += (1.0 - this->pruning) ;
    this->mature++ ;
}

Health* Health::clone(){
    return new Health() ;

}


float Health::healthScore() {
    return (this->water + this->fertalizer  + this->pruning)/originalHeathTotal ;
}


float Health::getWater() {
    return this->water ; 
}
float Health::getFertilizer() {
    return this->fertalizer ; 
}

float Health::healthPrune(){
    return this->pruning ; 
}

 int Health::getMaturity() {
    return this->mature;
 ;

 }

 bool Health::isAlive() {
    return (healthScore() > 0) ; 
 }


void Health::decay(int decayIndex) {

        switch (decayIndex) {
            case 0:
                std::cout << "\t[Decay] Before water decay: " << this->water << std::endl;
                this->water -= 0.4f;
                if (this->water < 0.0f) this->water = 0.0f;
                std::cout << "\t[Decay] After water decay: " << this->water << std::endl;
                break;
            case 1:
                std::cout << "\t[Decay] Before fertilizer decay: " << this->fertalizer << std::endl;
                this->fertalizer -= 0.4f;
                if (this->fertalizer < 0.0f) this->fertalizer = 0.0f;
                std::cout << "\t[Decay] After fertilizer decay: " << this->fertalizer << std::endl;
                break;
            case 2:
                std::cout << "\t[Decay] Before pruning decay: " << this->pruning << std::endl;
                this->pruning -= 0.4f;
                if (this->pruning < 0.0f) this->pruning = 0.0f;
                std::cout << "\t[Decay] After pruning decay: " << this->pruning << std::endl;
                break;
        }

}
