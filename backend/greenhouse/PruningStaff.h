#ifndef PRUNINGSTAFF_H
#define PRUNINGSTAFF_H

#include <string>
#include "GreenhouseStaff.h"
using namespace std;

class PruningStaff : public GreenhouseStaff {
    public:
        void update(string& careType, Plant* plant);
};

#endif