/**
 * @file Succulent.cpp
 * @brief Implements the functionality defined in the Succulent class.
 */

#include "Succulent.h"
#include "PlantHealth.h"
Succulent::Succulent(string variety,string difficulty) : Plant("Succulent", variety,difficulty) {
    this->health =  std::make_unique<Health>(2.0, 2.0, 2.0, 0) ;
}

Succulent::~Succulent() {

}

Plant* Succulent::clone()
{
    auto p = new Succulent(this->getPlantVariety(), this->getDifficulty());
    if (this->getHealth()) {
        p->health = this->getHealth()->clone();
    }
    p->generateId();
    return p;
}
