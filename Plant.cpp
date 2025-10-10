#include "Plant.h"

map<string, float> Plant::plantCosts = 
{
    {"Daisy", 5.0},
    {"Rose", 10.0},
    {"Sunflower", 8.5},
    {"Cactus", 12.0},
    {"Lemon", 15.0},
    {"Banana", 20.0},
    {"Apple", 25.0}
};

Plant::Plant(string plantType)
{
    this->plantType = plantType;

    costPrice = plantCosts[plantType];
    salePrice = costPrice * 1.5;
}

Plant::Plant(const Plant& original)
{

}

Plant::~Plant() {}