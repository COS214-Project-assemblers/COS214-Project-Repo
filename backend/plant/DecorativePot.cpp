#include "DecorativePot.h"
DecorativePot::DecorativePot(Plant* original) : PlantDecorator(original) {}

DecorativePot::~DecorativePot() {}

float DecorativePot::getSalePrice() {
    return plant->getSalePrice() + potPrice;
}
