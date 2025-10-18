#include "TreeCreator.h"

TreeCreator::TreeCreator() : PlantCreator() {}

TreeCreator::~TreeCreator() {}

Plant* TreeCreator::createPlant(string type)
{
    return new Tree(type);
}