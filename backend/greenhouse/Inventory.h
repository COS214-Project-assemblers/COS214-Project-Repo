#ifndef INVENTORY_H
#define INVENTORY_H

#include "Plant.h"

class Inventory
{
    private:
        vector<Plant*>* plants;
    
    public:
        Inventory();
        ~Inventory();

        /**
         * @brief Function that will be used for adding a Plant to the Inventory
         */
        void addPlant(Plant* p);
};

#endif