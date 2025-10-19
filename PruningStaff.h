#ifndef PRUNINGSTAFF_H
#define PRUNINGSTAFF_H

#include <string>
#include "Plant.h"
#include "GreenhouseStaff.h"

class PruningStaff : public GreenhouseStaff {
    public:
        void update(string& careType, Plant* plant);
};

#endif