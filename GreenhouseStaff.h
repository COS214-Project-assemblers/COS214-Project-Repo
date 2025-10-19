#ifndef GREENHOUSESTAFF_H
#define GREENHOUSESTAFF_H

class GreenhouseStaff {
    public:
        virtual void update(string& careType, Plant* plant) = 0;
};

#endif