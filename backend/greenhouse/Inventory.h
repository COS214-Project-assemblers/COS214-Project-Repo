/**
 * @class Inventory
 * @brief Stores a collections of plants, will return vectors of plants for the manager to choose from and then offer the client.
 * 
 * The Inventory class stores all available Plant objects that are availible for sale to clients, it allows for filtering based on a categoy or by a price range.
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Plant.h"

#include <vector>
#include <string>

class Inventory{
    private:
        std::vector<Plant*> plants;
    public:
        //no need to construct/deconstruct manually
        Inventory()=default;
        ~Inventory()=default;
        /**
         * @brief returns all plants in the inventory
         * @return A vector containing pointers to all Plant objects in the inventory
         */
        std::vector<Plant*> all() const;
        /**
         * @brief Commits a sale by removing the plant from the inventory
         * @param plant Reference to the Plant being sold
         */
        void commitSale(Plant* plant);
        /**
         * @brief Restocks a plantby adding it to the vector containing plants in the inventory
         * @param plant Reference to the Plant being restocked
         */
        //below is same as megans addPlant
        void restock(Plant* plant);
};

#endif