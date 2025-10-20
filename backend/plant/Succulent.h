#ifndef SUCCULENT_H
#define SUCCULENT_H

#include "Plant.h"

class Succulent : public Plant
{
    public:
        Succulent(string variety);
        ~Succulent();

        Plant* clone();
};

#endif