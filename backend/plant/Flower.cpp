/**
 * @file Flower.cpp
 * @brief Implements the functionality defined in the Flower class.
 */

#include "Flower.h"

Flower::Flower(string variety,string difficulty) : Plant("Flower", variety,difficulty) {}

Flower::~Flower() {}

Plant* Flower::clone()
{
    return new Flower(*this);
}