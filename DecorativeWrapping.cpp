#include "DecorativeWrapping.h"
DecorativeWrapping::DecorativeWrapping(const Plant& original)   : PlantDecorator(original) {}

DecorativeWrapping::~DecorativeWrapping() {}

float DecorativeWrapping::getSalePrice() {
    return plant->getSalePrice() + wrapperPrice;
}
