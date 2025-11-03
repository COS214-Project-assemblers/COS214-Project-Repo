/**
 * @file Inventory.h
 * @brief Inventory management for plants in greenhouse and sales floor
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Plant.h"

#include <vector>
#include <string>

/**
 * @class Inventory
 * @brief Manages collection of plants for sale and greenhouse operations
 * 
 * @see Plant
 * @see Manager
 * @see SalesFloor
 */
class Inventory{
    private:
        std::vector<Plant*> plants;  ///< Collection of plants in inventory

    public:

        /**
         * @brief Default constructor
         */
        Inventory()=default;

        /**
         * @brief Destructor - cleans up plant resources
         */
        ~Inventory();

        /**
         * @brief returns all plants in the inventory
         * @return A vector containing pointers to all Plant objects in the inventory
         */
        std::vector<Plant*> all() const;

        /**
         * @brief Restocks a plant by adding it to the vector containing plants in the inventory
         * @param plant Reference to the Plant being restocked
         */
        void restock(Plant* plant);

        /**
         * @brief removes a plant from the inventory
         * @param plant Reference to the Plant being removed
         */
        void removePlant(Plant* plant);

        /**
         * @brief Finds plants by care difficulty level
         * @param d Difficulty level to filter by ("Easy", "Moderate", "Hard")
         * @return Vector of plants matching specified difficulty
         */
        std::vector<Plant*> findByDifficulty(std::string d)const;

        /**
         * @brief Gets a specific plant by ID
         * @param id Plant identifier
         * @return Pointer to Plant if found, nullptr otherwise
         */
        Plant* getPlant(string id);
};

#endif