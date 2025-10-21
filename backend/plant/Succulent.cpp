/**
 * @file Plant.cpp
 * @brief Implements the functionality defined in the Succulent class.
 */

#include "Succulent.h"

Succulent::Succulent(string variety) : Plant("Succulent", variety) {}

Succulent::~Succulent() {}

Plant* Succulent::clone()
{
    return new Succulent(*this);
}