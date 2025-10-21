#include "WaterStaff.h"
#include "Plant.h"
#include "NotSellable.h"

void WaterStaff::update(string &careType, Plant *plant) {
    if (careType == "water") {
        std::cout << "WaterStaff: Watering " << plant->getPlantVariety() << " (" << plant->getPlantCategory() << ")...\n";
        plant->setState(new NotSellable()); // or progress toward Sellable
    }
}

/*
Example:

WaterStaff: Watering Rose (Flower)...

*/
