#include "FlowerCreator.h"

FlowerCreator::FlowerCreator() : PlantCreator() {}

FlowerCreator::~FlowerCreator() {}

Plant* FlowerCreator::createPlant(string type)
{
    return new Flower(type);
}