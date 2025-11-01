#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include "Inventory.h"

class Greenhouse
{
    private:
        Inventory* inventory;

    public:
        Greenhouse();
        ~Greenhouse();

        /**
         * @brief This function will be used to add a Plant into the inventory of the Greenhouse
         */
        void addPlant(Plant* p);

        Inventory* getInventory();
        /**
         * @brief removes a plant from the greenhouse inventory
         * @param plant Reference to the Plant being removed
         */
        void removePlant(Plant* plant);
};

#endif