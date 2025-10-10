#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <map>
using namespace std;

class Plant
{
    private:
        string plantType;
        float costPrice;
        float salePrice;

        static map<string, float> plantCosts;
    
    public:
        Plant(string plantType);
        Plant(const Plant& original);
        virtual ~Plant();
        
        virtual Plant* clone() = 0;
};

#endif