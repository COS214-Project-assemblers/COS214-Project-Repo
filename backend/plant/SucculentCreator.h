/**
 * @file SucculentCreator.h
 * @brief Defines the SucculentCreator class for creating Succulent objects.
 * @author Megan Norval
 *
 * This class implements the Factory Method defined in PlantCreator to
 * instantiate and manage Succulent-type Plant objects.
 */

#ifndef SUCCULENTCREATOR_H
#define SUCCULENTCREATOR_H

#include "PlantCreator.h"
#include "Succulent.h"

/**
 * @class SucculentCreator
 * @brief Concrete creator class responsible for creating Succulent objects.
 */
class SucculentCreator : public PlantCreator
{
    public:
        /**
         * @brief Constructs a SucculentCreator object.
         */
        SucculentCreator();

        /**
         * @brief Destroys the SucculentCreator object.
         */
        ~SucculentCreator();

        /**
         * @brief Creates a new Succulent object of the specified variety.
         * @param [in] type The variety of succulent to create (e.g., "Cactus", "Aloe").
         * @return A pointer to the newly created Succulent object.
         */
        Plant* createPlant(string type);
};

#endif