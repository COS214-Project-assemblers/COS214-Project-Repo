/**
 * @file Succulent.cpp
 * @brief Implements the functionality defined in the Succulent class.
 */

#include "Succulent.h"

Succulent::Succulent(string variety,string difficulty) : Plant("Succulent", variety, difficulty) {}

Succulent::~Succulent() {}

Plant* Succulent::clone()
{
    return new Succulent(*this);
}