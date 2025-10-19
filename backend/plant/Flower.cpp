#include "Flower.h"

Flower::Flower(string variety) : Plant("Flower", variety) {}

Flower::~Flower() {}

Plant* Flower::clone()
{
    return new Flower(*this);
}