/**
 * @file Succulent.cpp
 * @brief Implements the functionality defined in the Succulent class.
 */

#include "Succulent.h"
#include "PlantHealth.h"
Succulent::Succulent(string variety) : Plant("Succulent", variety) {
    this->health = new Health(2.0, 2.0, 2.0, 0) ;
}

Succulent::~Succulent() {

}

Plant* Succulent::clone()
{
    return new Succulent(*this);
}
