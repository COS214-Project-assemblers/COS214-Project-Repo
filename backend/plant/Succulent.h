/**
 * @file Succulent.h
 * @brief Defines the Succulent subclass derived from the Plant base class.
 * @author Megan Norval
 */

#ifndef SUCCULENT_H
#define SUCCULENT_H

#include "Plant.h"

/**
 * @class Succulent
 * @brief Represents a Succulent plant type within the greenhouse system.
 *
 * The Succulent class extends the abstract Plant base class, providing a concrete
 * implementation for creating and cloning Succulent objects.
 */
class Succulent : public Plant
{
    public:
        /**
         * @brief Constructs a Succulent object of a specific variety.
         * @param [in] variety The name of the succulent variety (e.g., "Cactus", "Aloe").
         * @param [in] difficulty The level of difficulty for care (Easy/Medium/Hard).
         */
        Succulent(string variety,string diffticulty);

        /**
         * @brief Destroys the Succulent object.
         */
        ~Succulent();

        /**
         * @brief Creates and returns a clone of this Succulent instance.
         * @return A pointer to the newly cloned Succulent object.
         */
        Plant* clone();
};

#endif