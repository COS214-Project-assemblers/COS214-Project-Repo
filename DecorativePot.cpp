#include "DecorativePot.h"
DecorativePot::DecorativePot(const Plant& original) : PlantDecorator(original) {}

DecorativePot::~DecorativePot() {}

float DecorativePot::getSalePrice() {
    return plant->getSalePrice() + potPrice;
}
