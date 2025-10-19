#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include "Plant.h"

class PlantCreator
{
    private:
        Plant* plant;

    protected:
        virtual Plant* createPlant(string type) = 0;

    public:
        PlantCreator();
        virtual ~PlantCreator();
        void makePlant(string type);
        Plant* clonePlant();

        bool hasPlant();
        Plant* getPlant();
};

#endif