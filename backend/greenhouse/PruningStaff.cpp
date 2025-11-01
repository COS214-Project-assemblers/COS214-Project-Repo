#include "PruningStaff.h"
#include "Plant.h"
#include "Sellable.h"

void PruningStaff::update(string &careType, Plant *plant) {
    if (careType == "pruning") {
        std::cout << "PruningStaff: Pruning " << plant->getPlantVariety() << " (" << plant->getPlantCategory() << ")...\n";
        plant->getHealth()->handlePruning() ;
        if (plant->getHealth()->getMaturity() == 3 ){
            plant->setState(new Sellable()); // could immediately progress to Sellable,                               // because if a plant needs pruning it's pretty much mature?
        }
    }
}

/*
Example:

PruningStaff: Pruning Apple Tree (Tree)...

*/
