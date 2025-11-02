/**
 * @file TreeCreator.cpp
 * @brief Implements the functionality defined in the TreeCreator class.
 */

#include "TreeCreator.h"

TreeCreator::TreeCreator() : PlantCreator() {}

TreeCreator::~TreeCreator() {}

Plant* TreeCreator::createPlant(string type)
{
    return new Tree(type, "hard");
}