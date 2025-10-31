#include "Greenhouse.h"

Greenhouse::Greenhouse()
{
    inventory = new Inventory();
}

Greenhouse::~Greenhouse()
{
    // might not delete??

    delete inventory;
}
 
void Greenhouse::addPlant(Plant* p)
{
    inventory->restock(p);
}

Inventory* Greenhouse::getInventory()
{
    return inventory;
}

void Greenhouse::removePlant(Plant* plant){
    this->inventory->removePlant(plant);
}