#include "Plant.h"

Plant::Plant(string plantType, float costPrice, float salePrice)
{
    bool valid = false;

    for (int i = 0; i < validPlants->size(); i++)
    {
        if(plantType == validPlants[i])
        {
            valid = true;
        }
    }
    
    if(valid)
    {
        this->plantType = plantType;
    }
    else
    {
        this->plantType = "Not valid";
    }

    if(costPrice > 0)
    {
        this->costPrice = costPrice;
    }
    else
    {
        this->costPrice = 1.00;
    }

    if(salePrice > 0)
    {
        this->salePrice = costPrice;
    }
    else
    {
        this->salePrice = 2.00;
    }

}

Plant::Plant(const Plant& original)
{

}

Plant::~Plant() {}