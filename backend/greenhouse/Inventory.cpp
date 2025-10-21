#include "Inventory.h"

Inventory::Inventory()
{
    plants = new vector<Plant*>();
}

Inventory::~Inventory()
{
    // might not delete??
    
    for (auto p : *plants) 
    {
        delete p;
    }

    delete plants;
}

void Inventory::addPlant(Plant* p)
{
    plants->push_back(p);
}