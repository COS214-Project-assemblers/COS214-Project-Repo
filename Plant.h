#ifndef PLANT_H
#define PLANT_H

#include <string>
using namespace std;

class Plant
{
    private:
        string plantType;
        float costPrice;
        float salePrice;

        const string validPlants[20] = 
        {"Daisy", "Rose", "Sunflower", "Cactus", "Lemon", "Banana", "Apple"};
    
    public:
        Plant(string plantType, float costPrice, float salePrice);
};

#endif