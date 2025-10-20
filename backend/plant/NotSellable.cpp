#include "NotSellable.h"

void NotSellable::handle(Plant *plant) {
    std::cout << plant->getPlantVariety() << "(" << plant->getPlantCategory()
    << ") still needs care to reach a Sellable state."<< std::endl;
    
    /*  Potential behaviours to be added here:
        
        // Notify observers again
        // std::string careType = plant->getCareType();
        // plant->notify(careType);

        - After staff provides care via update(),
          they will call plant->setState(new Sellable());

    */
}