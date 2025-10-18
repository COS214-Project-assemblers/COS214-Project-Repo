#include "PlantDecorator.h"
PlantDecorator::PlantDecorator(const Plant& original) : Plant(original) {
    this->plant=original.clone() // clone to make a deep copy of the wrapped plant - this decorator OWNS this clone 
}

PlantDecorator::~PlantDecorator() {
    // The destruction of the decorators plant depends on who is
    // taking ownership of this dynamic memory

    // Currently (18-10-2025) I believe that is the responsibility fo the client
    // and therefore will not be de-allocating the pointer here as
    // this will destroy the specific plant object the client is working with
    delete this->plant ;
    this->plant = NULL ;
}
