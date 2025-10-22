#include "Inventory.h"
//ally - can just use default constructors & deconstrucotrs
// Inventory::Inventory()
// {
//     plants = new std::vector<Plant*>();
// }

// Inventory::~Inventory()
// {
//     // might not delete??
    
//     for (auto p : *plants) 
//     {
//         delete p;
//     }

//     delete plants;
// }


std::vector<Plant*> Inventory::all() const{
    std::vector<Plant*> out;
    for(auto* p:plants){
        out.push_back(p);
    }
    return out;
}

// std::vector<Plant*> Inventory::findByCategory(std::string cat) const{

// }


// std::vector<Plant*> Inventory::findByPrice(double min, double max) const{

// }

std::vector<Plant*> Inventory::findByDifficulty(std::string d){
    std::vector<Plant*> out;
    for(auto* p:plants){
        if(p->getDifficulty()==d){
            out.push_back(p);
        }
    }
    return out;
}

void Inventory::commitSale(Plant* plant){

}

void Inventory::restock(Plant* plant){
    plants.push_back(plant);
}
