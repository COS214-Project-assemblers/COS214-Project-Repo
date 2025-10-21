/**
 * @file FlowerCreator.h
 * @brief Defines the FlowerCreator class for creating Flower objects.
 *
 * This class implements the Factory Method defined in PlantCreator to
 * instantiate and manage Flower-type Plant objects.
 */

#ifndef FLOWERCREATOR_H
#define FLOWERCREATOR_H

#include "PlantCreator.h"
#include "Flower.h"

/**
 * @class FlowerCreator
 * @brief Concrete creator class responsible for creating Flower objects.
 */
class FlowerCreator : public PlantCreator
{
    public:
        /**
         * @brief Constructs a FlowerCreator object.
         */
        FlowerCreator();

        /**
         * @brief Destroys the FlowerCreator object.
         */
        ~FlowerCreator();

        /**
         * @brief Creates a new Flower object of the specified variety.
         * @param [in] type The variety of flower to create (e.g., "Daisy", "Rose").
         * @return A pointer to the newly created Flower object.
         */
        Plant* createPlant(string type);
};

#endif