/**
 * @file FlowerCreator.cpp
 * @brief Implements the functionality defined in the FlowerCreator class.
 */

#include "FlowerCreator.h"

FlowerCreator::FlowerCreator() : PlantCreator() {}

FlowerCreator::~FlowerCreator() {}

Plant* FlowerCreator::createPlant(string type)
{
    return new Flower(type, "medium");
}