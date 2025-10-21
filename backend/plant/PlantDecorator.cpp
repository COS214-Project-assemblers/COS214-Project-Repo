
#include "PlantDecorator.h"
PlantDecorator::PlantDecorator(Plant* original) : Plant(*original) {
    // clone to make a deep copy of the wrapped plant - this decorator OWNS this clone
    this->plant = original->clone()  ;
}

PlantDecorator::~PlantDecorator() {
    delete this->plant ;
    this->plant = NULL ;
}
