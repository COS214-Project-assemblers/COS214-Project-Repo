#include "DecorativeArrangement.h"

DecorativeArrangement::DecorativeArrangement(Plant* original) : PlantDecorator(original) {}

DecorativeArrangement::~DecorativeArrangement() {}

float DecorativeArrangement::getSalePrice() {
    return plant->getSalePrice() + arrangementPrice;
}
