#include "FertilizerStaff.h"
#include "Plant.h"
#include "NotSellable.h"

void FertilizerStaff::update(string &careType, Plant *plant) {
    if (careType == "fertilizer") {
        std::cout << "FertilizerStaff: Fertilizing " << plant->getPlantVariety() << " (" << plant->getPlantCategory() << ")...\n";
        plant->setState(new NotSellable()); // or progress toward Sellable
        plant->getHealth()->handleFertilizer() ;
    }
}

/*
Example:

FertilizerStaff: Fertilizing Rose (Flower)...

*/
