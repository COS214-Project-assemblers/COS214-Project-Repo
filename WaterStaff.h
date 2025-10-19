#ifndef WATERSTAFF_H
#define WATERSTAFF_H

#include <string>
#include "Plant.h"
#include "GreenhouseStaff.h"

class WaterStaff : public GreenhouseStaff {
    public:
        void update(string& careType, Plant* plant);
};

#endif