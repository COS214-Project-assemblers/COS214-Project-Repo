#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "PlantCreator.h"
#include "Tree.h"

class TreeCreator : public PlantCreator
{
    public:
        TreeCreator();
        ~TreeCreator();

        Plant* createPlant(string type);
};

#endif