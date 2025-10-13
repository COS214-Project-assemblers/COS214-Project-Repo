#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

class Flower : public Plant
{
    public:
        Flower(string variety);
        ~Flower();

        Plant* clone();
};

#endif