/**
 * @file Flower.cpp
 * @brief Implements the functionality defined in the Flower class.
 */

#include "Flower.h"
#include "PlantHealth.h"
Flower::Flower(string variety,string difficulty) : Plant("Flower",variety,difficulty) {
    this->health = std::make_unique<Health>() ;
}

Flower::~Flower() {}

Plant* Flower::clone()
{
    auto p = new Flower(this->getPlantVariety(), this->getDifficulty());
    if (this->getHealth()) {
        p->health = this->getHealth()->clone();
    }
    p->generateId();
    return p;
}
