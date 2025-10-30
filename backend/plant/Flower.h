/**
 * @file Flower.h
 * @brief Defines the Flower subclass derived from the Plant base class.
 */

#ifndef FLOWER_H
#define FLOWER_H

#include "Plant.h"

/**
 * @class Flower
 * @brief Represents a Flower plant type within the greenhouse system.
 *
 * The Flower class extends the abstract Plant class and provides a concrete
 * implementation for creating and cloning Flower objects.
 */
class Flower : public Plant
{
    public:
        /**
         * @brief Constructs a Flower object of a specific variety.
         * @param [in] variety The name of the flower variety (e.g., "Daisy", "Rose").
         * @param [in] difficulty The level of difficulty for care (Easy/Medium/Hard)
         */
        Flower(string variety,string difficulty);
        // Flower(string variety);


        /**
         * @brief Destroys the Flower object.
         */
        ~Flower();

        /**
         * @brief Creates and returns a clone of this Flower instance.
         * @return A pointer to the newly cloned Flower object.
         */
        Plant* clone();
};

#endif