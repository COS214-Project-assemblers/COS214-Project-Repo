#ifndef FLOWERCREATOR_H
#define FLOWERCREATOR_H

#include "PlantCreator.h"
#include "Flower.h"

class FlowerCreator : public PlantCreator
{
    public:
        FlowerCreator();
        ~FlowerCreator();

        Plant* createPlant(string type);
};

#endif