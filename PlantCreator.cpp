#include "PlantCreator.h"

PlantCreator::PlantCreator() {}

PlantCreator::~PlantCreator()
{
    // might delete plant, but might not?
}

void PlantCreator::anOperation()
{
    plant = createPlant();
}

Plant* PlantCreator::clonePlant()
{
    if(plant)
    {
        return plant->clone();
    }

    return nullptr;
}