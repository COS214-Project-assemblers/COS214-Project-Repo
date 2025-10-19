#ifndef INVENTORY_H
#define INVENTORY_H

#include "Plant.h"

#include <vector>
#include <string>

class Inventory{
    private:
        Plant* plants;
    public:
        //did not include other peoples func!
        std::vector<Plant*> all() const;
        std::vector<Plant*> findByCategory(std::string cat) const;
        std::vector<Plant*> findByPrice(double min, double max) const;
        bool commitSale(Plant& plant);
        bool restock(Plant& plant);
};

#endif