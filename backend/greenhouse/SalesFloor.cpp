#include "SalesFloor.h"

SalesFloor::SalesFloor(){
    inv = new Inventory();
}

SalesFloor::~SalesFloor()
{
    if(inv)
    {
        delete inv;
    }
}

const Inventory* SalesFloor::inventory()const{
    if(!this->inv){
        throw std::runtime_error("SalesFloor::inventory() called before inventory is set");
    }
    return this->inv;
}

Inventory& SalesFloor::inventoryMut(){
    if(!this->inv){
        throw std::runtime_error("SalesFloor::inventory() called before inventory is set");
    }
    return *this->inv;
}

Ledger& SalesFloor::getLedger(){
    return this->ledger;
}

const Ledger& SalesFloor::getLedger()const{
    return this->ledger;
}

void SalesFloor::addPlant(Plant* p)
{
    inv->restock(p);
}

Plant* SalesFloor::getPlantOnSalesFloor(string id)
{
    return inv->getPlant(id);
}

Plant* SalesFloor::removePlantFromSalesFloor(string id)
{
    Plant* plantToRemove =inv->getPlant(id);

    if (plantToRemove == nullptr) return nullptr;

    inv->removePlant(plantToRemove);

    return plantToRemove;
}