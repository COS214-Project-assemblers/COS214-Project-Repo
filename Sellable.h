#ifndef SELLABLE_H
#define SELLABLE_H

#include "PlantState.h"

class Sellable : public PlantState {
    public:
        void handle(Plant* plant);
};

#endif