#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include "Plant.h"

/**
 * @class PlantState
 * @brief Abstract base class representing different states of a plant.
 * 
 * This class defines the interface for all concrete plant states in the State pattern.
 * Each state represents a specific phase of a plant's lifecycle 
 * (Sellable, NotSellable) and defines behaviour specific to that state.
 */
class PlantState {
    public:

        /**
         * @brief Handles the plant's behaviour in the current state.
         * 
         * This pure virtual method defines state-specific behaviour. Concrete state
         * classes must implement this method to handle the plant's actions and 
         * potentially transition to another state.
         * 
         * @param plant Pointer to the plant whose state is being handled
         */
        virtual void handle(Plant* plant) = 0;

        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~PlantState() = default;

        virtual string getState() = 0;
};

#endif