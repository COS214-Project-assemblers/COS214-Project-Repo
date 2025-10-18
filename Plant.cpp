#include "Plant.h"

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
}

Plant::~Plant() {}

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