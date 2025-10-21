/**
 * @file Flower.cpp
 * @brief Implements the functionality defined in the Flower class.
 */

#include "Flower.h"

Flower::Flower(string variety) : Plant("Flower", variety) {}

Flower::~Flower() {}

Plant* Flower::clone()
{
    return new Flower(*this);
}