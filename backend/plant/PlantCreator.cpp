/**
 * @file PlantCreator.cpp
 * @brief Implements the functionality defined in the PlantCreator class.
 */

#include "PlantCreator.h"

PlantCreator::PlantCreator() 
{
    plant = nullptr;
}

PlantCreator::~PlantCreator()
{
    // WATCH OUT, IF SEG THEN REMOVE THIS
    if (plant != nullptr) {
        delete plant;
    }
}

void PlantCreator::makePlant(string type)
{
    if (plant != nullptr) delete plant;
    plant = createPlant(type);
}

Plant* PlantCreator::clonePlant()
{
    if(plant)
    {
        return plant->clone();
    }

    return nullptr;
}

bool PlantCreator::hasPlant()
{ 
    if(plant)
    {
        return true;
    }
    
    return false;
}

Plant* PlantCreator::getPlant()
{ 
    return plant; 
}