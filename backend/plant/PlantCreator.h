/**
 * @file PlantCreator.h
 * @brief Defines the abstract PlantCreator class used in the Factory/Prototype creation process.
 * @author Megan Norval
 *
 * This class provides a framework for creating and cloning Plant objects.
 * It serves as the base for concrete creators that produce specific categories of plants.
 */

#ifndef PLANTCREATOR_H
#define PLANTCREATOR_H

#include "Plant.h"

/**
 * @class PlantCreator
 * @brief Abstract base class responsible for creating and managing Plant objects.
 *
 * The PlantCreator class defines the interface for plant creation using
 * the Factory Method design pattern and supports cloning via the Prototype pattern.
 */
class PlantCreator
{
    private:
        /**
         * @brief Pointer to a Plant object managed by the creator.
         */
        Plant* plant = nullptr;

    protected:
        /**
         * @brief Creates a Plant object of the specified type.
         * @details This pure virtual function must be implemented by subclasses
         *          to instantiate specific varieties of plants.
         * @param [in] type The variety of plant to create.
         * @return A pointer to the newly created Plant object.
         */
        virtual Plant* createPlant(string type) = 0;

    public:
        /**
         * @brief Default constructor for the PlantCreator class.
         */
        PlantCreator();

        /**
         * @brief Virtual destructor to ensure proper cleanup in derived classes.
         */
        virtual ~PlantCreator();

        /**
         * @brief Creates and stores a new Plant object of the specified variety.
         * @param [in] type The variety of plant to create.
         */
        void makePlant(string type);

        /**
         * @brief Creates and returns a clone of the currently stored Plant object.
         * @return A pointer to the cloned Plant, or nullptr if no plant exists.
         */
        Plant* clonePlant();

        /**
         * @brief Checks whether the creator currently holds a Plant object.
         * @return True if a plant exists, false otherwise.
         */
        bool hasPlant();

        /**
         * @brief Retrieves the currently stored Plant object.
         * @return A pointer to the Plant instance managed by the creator.
         */
        Plant* getPlant();
};

#endif