#ifndef NOTSELLABLE_H
#define NOTSELLABLE_H

#include "PlantState.h"
#include <string>

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

        /**
         * @brief Creates a deep copy of this NotSellable state.
         * @return Pointer to a newly allocated copy of this NotSellable state
         */
        PlantState* clone() const override;
};

#endif