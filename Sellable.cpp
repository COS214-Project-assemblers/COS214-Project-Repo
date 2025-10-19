#include "Sellable.h"

void Sellable::handle(Plant *plant) {
    
}

PlantState *Sellable::clone() const {
    return new Sellable(*this);
}