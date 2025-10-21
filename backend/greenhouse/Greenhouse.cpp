#include "Greenhouse.h"

Greenhouse::Greenhouse()
{

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