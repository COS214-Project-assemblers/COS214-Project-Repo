/**
 * @file Flower.cpp
 * @brief Implements the functionality defined in the Flower class.
 */

#include "Flower.h"
#include "PlantHealth.h"
Flower::Flower(string variety) : Plant("Flower", variety) {
    this->health = new Health() ;
}

Flower::~Flower() {}

Plant* Flower::clone()
{
    return new Flower(*this);
}
