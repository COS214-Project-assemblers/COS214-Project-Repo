#include "Inventory.h"
//ally - can just use default constructors & deconstrucotrs
// Inventory::Inventory()
// {
//     plants = new std::vector<Plant*>();
// }

Inventory::~Inventory()
{
    for (Plant* p : plants) 
    {
        if(p != nullptr)
        {
            delete p;
        }
    }

    plants.clear();
}


std::vector<Plant*> Inventory::all() const{
    std::vector<Plant*> out;
    for(auto* p:plants){
        out.push_back(p);
    }
    return out;
}

void Inventory::restock(Plant* plant){
    plants.push_back(plant);
}

void Inventory::removePlant(Plant* plant){
    auto it=std::find(plants.begin(), plants.end(), plant);
    if(it!=plants.end()){
        plants.erase(it);
    }
}

std::vector<Plant*> Inventory::findByDifficulty(std::string d)const{
    std::vector<Plant*> out;
    for(auto* p:this->plants){
        if(p->getDifficulty()==d){
            out.push_back(p);
        }
    }
    return out;
}

void Inventory::commitSale(Plant* plant)
{
    removePlant(plant);
}