/**
 * @file Sellable.h
 * @brief Concrete state for plants ready for sale
 */

#ifndef SELLABLE_H
#define SELLABLE_H

#include <iostream>
#include <string>
#include "PlantState.h"

/**
 * @class Sellable
 * @brief Concrete state class representing a plant that is ready for sale.
 * 
 * This class represents the state where a plant has matured sufficiently and
 * meets all quality criteria to be sold to customers. In this state, the plant
 * can be moved to the SalesFloor.
 */
class Sellable : public PlantState {
    public:

        /**
         * @brief Handles the plant's behaviour when it is in a sellable state.
         * @param plant Pointer to the plant being handled
         */
        void handle(Plant* plant);

        /**
         * @brief Gets the state name
         * @return "Sellable" string
         */
        string getState();
};

#endif