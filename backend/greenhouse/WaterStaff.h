#ifndef WATERSTAFF_H
#define WATERSTAFF_H

#include <string>
#include "GreenhouseStaff.h"
using namespace std;

class WaterStaff : public GreenhouseStaff {
    public:
        void update(string& careType, Plant* plant);
};

#endif