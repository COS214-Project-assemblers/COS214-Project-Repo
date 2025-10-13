#include "Succulent.h"

Succulent::Succulent(string variety) : Plant("Succulent", variety) {}

Succulent::~Succulent() {}

Plant* Succulent::clone()
{
    return new Succulent(*this);
}
