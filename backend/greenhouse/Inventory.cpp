#include "Inventory.h"
//ally - can just use default constructors & deconstrucotrs
// Inventory::Inventory()
// {
//     plants = new std::vector<Plant*>();
// }

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define CYAN    "\033[36m"

Inventory::~Inventory()
{
    std::cout <<RED << "\tInventory::~Inventory() - delete inventory;" << RESET << std::endl ; 

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