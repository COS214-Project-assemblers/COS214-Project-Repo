#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include "Plant.h"

class PlantCreator
{
    private:
        Plant* plant;

    protected:
        virtual Plant* createPlant() = 0;

    public:
        PlantCreator();
        virtual ~PlantCreator();
        void anOperation();
        Plant* clonePlant();
};

#endif