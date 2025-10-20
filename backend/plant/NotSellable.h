#ifndef NOTSELLABLE_H
#define NOTSELLABLE_H

#include "PlantState.h"

class NotSellable : public PlantState {
    public:
        void handle(Plant* plant);
        PlantState* clone() const override;
};

#endif