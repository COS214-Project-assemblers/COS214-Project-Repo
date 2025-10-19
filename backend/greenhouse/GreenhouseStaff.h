#ifndef GREENHOUSESTAFF_H
#define GREENHOUSESTAFF_H

#include <string>

class Plant;

using namespace std;

class GreenhouseStaff {
    public:
        virtual void update(string& careType, Plant* plant) = 0;
        virtual ~GreenhouseStaff() = default;
};

#endif