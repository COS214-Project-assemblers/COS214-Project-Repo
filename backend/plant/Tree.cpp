/**
 * @file Tree.cpp
 * @brief Implements the functionality defined in the Tree class.
 */

#include "Tree.h"
#include "PlantHealth.h"
Tree::Tree(string variety) : Plant("Tree", variety) {
    /**
     * Different Concrete Plants initalise their Healths' differently so that they
     * decay at different rates, E.G succulents are watered less than flowers
     */
    this->health = new Health(2.0, 2.0, 1.0, 0) ;
}

Tree::~Tree() {}

Plant* Tree::clone()
{
    return new Tree(*this);
}
