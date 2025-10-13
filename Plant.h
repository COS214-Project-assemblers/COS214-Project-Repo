#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <map>
#include <iostream>
using namespace std;

class Plant
{
    private:
        string plantCategory;
        string plantVariety;
        float costPrice;
        float salePrice;

        static map<string, float> plantCosts;
    
    public:
        Plant(string category, string variety);
        Plant(const Plant& original);
        virtual ~Plant();
        
        virtual Plant* clone() = 0;

        string getPlantCategory();
        string getPlantVariety();
        float getCostPrice();
        float getSalePrice();
        
        virtual void display();
};

#endif