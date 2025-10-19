#ifndef FERTILIZERSTAFF_H
#define FERTILIZERSTAFF_H

#include <string>
#include "Plant.h"
#include "GreenhouseStaff.h"

class FertilizerStaff : public GreenhouseStaff {
    public:
        void update(string& careType, Plant* plant);
};

#endif