#include "Inventory.h"

<<<<<<< HEAD
std::vector<Plant*> Inventory::all() const{

}

std::vector<Plant*> Inventory::findByCategory(std::string cat) const{

}

std::vector<Plant*> Inventory::findByPrice(double min, double max) const{

}

bool Inventory::commitSale(Plant& plant){

}

bool Inventory::restock(Plant& plant){

}
=======
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
>>>>>>> dev
