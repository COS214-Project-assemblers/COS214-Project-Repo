#include "NotSellable.h"

void NotSellable::handle(Plant *plant) {
    
}

PlantState *NotSellable::clone() const {
    return new NotSellable(*this);
}