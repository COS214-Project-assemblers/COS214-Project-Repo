/**
 * @file Tree.h
 * @brief Defines the Tree subclass derived from the Plant base class.
 */

#ifndef TREE_H
#define TREE_H

#include "Plant.h"

/**
 * @class Tree
 * @brief Represents a Tree plant type within the greenhouse system.
 *
 * The Tree class extends the abstract Plant base class, providing a concrete
 * implementation for creating and cloning Tree objects.
 */
class Tree : public Plant
{
    public:
        /**
         * @brief Constructs a Tree object of a specific variety.
         * @param [in] variety The name of the tree variety (e.g., "Lemon", "Oak").
         * @param [in] difficulty The level of difficulty for care (Easy/Medium/Hard)
         */
        Tree(string variety, string difficulty);

        /**
         * @brief Destroys the Tree object.
         */
        ~Tree();

        /**
         * @brief Creates and returns a clone of this Tree instance.
         * @return A pointer to the newly cloned Tree object.
         */
        Plant* clone();
};

#endif