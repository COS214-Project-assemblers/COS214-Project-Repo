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
    inventory->addPlant(p);
}