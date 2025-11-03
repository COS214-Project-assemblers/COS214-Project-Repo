/**
 * @file GreenhouseStaff.h
 * @brief Abstract base class for greenhouse staff observers
 */
#ifndef GREENHOUSESTAFF_H
#define GREENHOUSESTAFF_H

#include <string>
#include "PlantHealth.h"
class Greenhouse;
class Plant;

using namespace std;

/**
 * @class GreenhouseStaff
 * @brief Abstract base class for greenhouse staff observers.
 *
 * This class defines the interface for greenhouse staff members who need to be
 * notified when plants require care. It follows the Observer pattern where
 * staff members are observers of plant state changes.
 */

class GreenhouseStaff {
    protected:
        Greenhouse* greenhouse;  ///< Reference to greenhouse for plant operations

    public:

        /**
         * @brief Updates the staff member about a plant's care requirements.
         *
         * This pure virtual method is called when a plant needs attention.
         * Derived classes must implement this method to define specific
         * responses to plant care needs.
         *
         * @param careType The type of care required ("water", "fertilizer", "pruning")
         * @param plant Pointer to the plant that needs care
         */
        virtual void update(const string& careType, Plant* plant) = 0;

        /**
         * @brief Virtual destructor for proper cleanup of derived classes.
         */
        virtual ~GreenhouseStaff() = default;

        /**
         * @brief Sets the greenhouse reference for staff operations
         * @param greenhouse Pointer to Greenhouse instance
         */
        void setGreenhouse(Greenhouse* greenhouse);
};

#endif
