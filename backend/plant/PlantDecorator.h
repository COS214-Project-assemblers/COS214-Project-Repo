#ifndef DECORATIVE_WRAPPER_H
#define DECORATIVE_WRAPPER_H

#include <iostream>
#include "Plant.h"



/**
 * @class PlantDecorator
 * @brief Abstract base class for all plant decorators.
 *
 * This class implements the Decorator design pattern so that Customers can Customize
 * the plants they purchase at check-out (check-out == run-time)
 * (This Feature is part of the functional requirements)
 *
 * A Note On MEMORY Ownership:
 * - Each PlantDecorator OWNS its' Plant plant because it CLONES the passed in plant object.
 * - The destructor deletes the wrapped Plant AND only the outermost decorator needs to be
 *   explicitly deleted it will recursively delete all wrapped objects.
 */

class PlantDecorator : public Plant {
    public:

    /**
     * @brief Constructs a PlantDecorator wrapping a given Plant.
     * @param original The Plant object to wrap. A clone is stored internally.
     */
    PlantDecorator(Plant* original) ;

    /**
     * @brief Destructor.
     *
     * Deletes the internally stored Plant clone.
     * Only the outermost decorator needs to be deleted explicitly.
     */
    virtual ~PlantDecorator() ;

    /**
     * @brief Pure virtual function for retrieving sale price.
     * Corresponds to the operation() function in the Decorator Design Pattern
     * Each concrete decorator adds its own cost to the wrapped Plant's sale price.
     * @return The total sale price that has added on decoration prices.
     */
     virtual float getSalePrice() = 0 ;  // this is the operation() function from "context" class

    protected:
    Plant* plant ; ///< Pointer to the wrapped Plant (OWNED by this decorator)

} ;

#endif

/******* Example Usage Of Plant Decorator *****************//*

Plant* rose = new Flower();
Plant* decorated = new DecorativeWrapper( new DecorativeArrangement(rose) );

float price = decorated->getSalePrice();

delete decorated; // automatically deletes the DecorativeArrangement(rose) and the original rose CLONE - NOT The original rose pointer
delete rose ; // hence this still needs to be deleted

*//********************************************************/
