#include "Sellable.h"

void Sellable::handle(Plant *plant) {
    std::cout << plant->getPlantVariety() << "(" << plant->getPlantCategory()
    << ") is now ready for sale at R" << plant->getSalePrice() << std::endl;
    
    /*  Potential behaviours to be added here:
        - Trigger to move the plant to the SalesFloor
        - Update plant as available in inventory?
    */
}

string Sellable::getState()
{
    return "Sellable";
}