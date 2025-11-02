#ifndef NOTSELLABLE_H
#define NOTSELLABLE_H

#include <iostream>
#include <string>
#include "PlantState.h"

/**
 * @class NotSellable
 * @brief Concrete state class representing a plant that is not ready for sale.
 * 
 * This class represents the state where a plant has not yet matured sufficiently
 * or does not meet quality criteria to be sold to customers. Plants in this state
 * may require additional care and growth time before transitioning to
 * a Sellable state.
 */
class NotSellable : public PlantState {
    public:

        /**
         * @brief Handles the plant's behaviour when it is not ready for sale.
         * @param plant Pointer to the plant being handled
         */
        void handle(Plant* plant);

        string getState();
};

#endif