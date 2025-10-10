#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include "Plant.h"

class PlantCreator
{
    private:
        Plant* plant;

    protected:
        Plant* createPlant();

    public:
        PlantCreator();
        virtual ~PlantCreator();
        void anOperation();
        Plant* clonePlant();
};

#endif