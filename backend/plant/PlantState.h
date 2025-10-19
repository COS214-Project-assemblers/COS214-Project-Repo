#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include "Plant.h"

class PlantState {
    public:
        virtual void handle(Plant* plant) = 0;
        virtual PlantState* clone() const = 0;
        virtual ~PlantState() = default;
};

#endif