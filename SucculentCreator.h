#ifndef SUCCULENTCREATOR_H
#define SUCCULENTCREATOR_H

#include "PlantCreator.h"
#include "Succulent.h"

class SucculentCreator : public PlantCreator
{
    public:
        SucculentCreator();
        ~SucculentCreator();

        Plant* createPlant(string type);
};

#endif