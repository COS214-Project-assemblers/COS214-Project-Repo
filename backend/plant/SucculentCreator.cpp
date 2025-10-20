#include "SucculentCreator.h"

SucculentCreator::SucculentCreator() : PlantCreator() {}

SucculentCreator::~SucculentCreator() {}

Plant* SucculentCreator::createPlant(string type)
{
    return new Succulent(type);
}