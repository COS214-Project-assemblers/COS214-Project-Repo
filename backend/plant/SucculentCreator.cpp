/**
 * @file SucculentCreator.cpp
 * @brief Implements the functionality defined in the SucculentCreator class.
 */

#include "SucculentCreator.h"

SucculentCreator::SucculentCreator() : PlantCreator() {}

SucculentCreator::~SucculentCreator() {}

Plant* SucculentCreator::createPlant(string type)
{
    return new Succulent(type, "easy");
}