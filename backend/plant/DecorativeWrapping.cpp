#include "DecorativeWrapping.h"
DecorativeWrapping::DecorativeWrapping(Plant* original)   : PlantDecorator(original) {}

DecorativeWrapping::~DecorativeWrapping() {}

float DecorativeWrapping::getSalePrice() {
    return plant->getSalePrice() + wrapperPrice;
}
