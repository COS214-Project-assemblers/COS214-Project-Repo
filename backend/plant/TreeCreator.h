/**
 * @file TreeCreator.h
 * @brief Defines the TreeCreator class for creating Tree objects.
 *
 * This class implements the Factory Method defined in PlantCreator to
 * instantiate and manage Tree-type Plant objects.
 */

#ifndef TREECREATOR_H
#define TREECREATOR_H

#include "PlantCreator.h"
#include "Tree.h"

/**
 * @class TreeCreator
 * @brief Concrete creator class responsible for creating Tree objects.
 */
class TreeCreator : public PlantCreator
{
    public:
        /**
         * @brief Constructs a TreeCreator object.
         */
        TreeCreator();

        /**
         * @brief Destroys the TreeCreator object.
         */
        ~TreeCreator();

        /**
         * @brief Creates a new Tree object of the specified variety.
         * @param [in] type The variety of tree to create (e.g., "Lemon", "Apple").
         * @return A pointer to the newly created Tree object.
         */
        Plant* createPlant(string type);
};

#endif