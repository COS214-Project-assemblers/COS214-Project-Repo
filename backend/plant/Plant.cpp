#include "Plant.h"
#include "NotSellable.h"
#include "GreenhouseStaff.h"

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

    this->plantState = new NotSellable();
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
    observerList.push_back(ob);
}

void Plant::detach(GreenhouseStaff *ob) {
    for (int i = 0; i < observerList.size(); i++){
        if(observerList[i] == ob){
            observerList.erase(observerList.begin() + i);
        }
    }
}

void Plant::notify(std::string& careType) {
    for(GreenhouseStaff* observer : observerList) {
        observer->update(careType, this);
    }
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
    plantState->handle(this);
}