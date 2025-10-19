#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <map>
#include <iostream>

class PlantState;
class GreenhouseStaff;

using namespace std;

class Plant
{
    private:
        string plantCategory;
        string plantVariety;
        float costPrice;
        float salePrice;

        PlantState* plantState;
        string careType;

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

        void display();

        PlantState* getState();
        void attach(GreenhouseStaff* ob);
        void detach(GreenhouseStaff* ob);
        void notify(string& careType);
        string getCareType();
        void setState(PlantState* plantState);
        void request();
};

#endif