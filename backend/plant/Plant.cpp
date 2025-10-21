/**
 * @file Plant.cpp
 * @brief Implements the functionality defined in the Plant class.
 */

#include "Plant.h"
#include "NotSellable.h"

map<string, float> Plant::plantCosts = 
{
    {"Rose", 10.0},
    {"Daisy", 5.0},
    {"Sunflower", 8.5},
    
    {"Cactus", 12.0},
    {"Aloe", 9.0},
    {"Jade", 7.5},
    
    {"Lemon", 15.0},
    {"Banana", 20.0},
    {"Apple", 25.0}
};

Plant::Plant(string category, string variety)
{
    this->plantCategory = category;
    this->plantVariety = variety;

    this->careType = "";
    this->plantState = new NotSellable();

    if(plantCosts[variety])
    {
        costPrice = plantCosts[variety];
    }
    else
    {
        costPrice = 10.00;
    }
    
    salePrice = costPrice * 1.5;
}

Plant::Plant(const Plant& original)
{
    this->plantCategory = original.plantCategory;
    this->plantVariety = original.plantVariety;
    this->costPrice = original.costPrice;
    this->salePrice = original.salePrice;

    if(original.plantState != nullptr) { 
        this->plantState = original.plantState->clone(); 
    } else { 
        this->plantState = nullptr; 
    }
    this->careType = original.careType;
}

Plant::~Plant() {
    delete plantState;
}

string Plant::getPlantCategory()
{
    return plantCategory;
}

string Plant::getPlantVariety()
{ 
    return plantVariety; 
}

float Plant::getCostPrice()
{ 
    return costPrice; 
}

float Plant::getSalePrice()
{ 
    return salePrice; 
}

void Plant::display()
{
    cout << plantCategory << " - " << plantVariety << ", Cost: R" << costPrice << ", Sale: R" << salePrice << endl;
}



PlantState *Plant::getState() {
    return plantState;
}

void Plant::attach(GreenhouseStaff *ob) {

}

void Plant::detach(GreenhouseStaff *ob) {

}

void Plant::notify(std::string& careType) {

}

std::string Plant::getCareType() {
    return careType;
}

void Plant::setState(PlantState *plantState_) {
    if(plantState != plantState_) {
        delete plantState;
        plantState = plantState_;
    }
}

void Plant::request() {

}