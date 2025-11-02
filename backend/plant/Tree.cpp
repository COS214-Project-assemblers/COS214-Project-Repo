/**
 * @file Tree.cpp
 * @brief Implements the functionality defined in the Tree class.
 */

#include "Tree.h"
#include "PlantHealth.h"
Tree::Tree(string variety,string difficulty) : Plant("Tree", variety,difficulty) {
    /**
     * Different Concrete Plants initalise their Healths' differently so that they
     * decay at different rates, E.G succulents are watered less than flowers
     */
    this->health = std::make_unique<Health>(2.0, 2.0, 1.0, 0) ;
}

Tree::~Tree() {}

Plant* Tree::clone()
{
    auto p = new Tree(this->getPlantVariety(), this->getDifficulty());
    if (this->getHealth()) {
        p->health = this->getHealth()->clone();
    }
    p->generateId();
    return p;
}
