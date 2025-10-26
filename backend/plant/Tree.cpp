/**
 * @file Tree.cpp
 * @brief Implements the functionality defined in the Tree class.
 */

#include "Tree.h"
#include "PlantHealth.h"
Tree::Tree(string variety) : Plant("Tree", variety) {
    this->health = new Health(2.0, 2.0, 1.0, 0) ;
}

Tree::~Tree() {}

Plant* Tree::clone()
{
    return new Tree(*this);
}
