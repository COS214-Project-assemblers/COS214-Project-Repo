/**
 * @file Tree.cpp
 * @brief Implements the functionality defined in the Tree class.
 */

#include "Tree.h"

Tree::Tree(string variety, string difficulty) : Plant("Tree", variety, difficulty) {}

Tree::~Tree() {}

Plant* Tree::clone()
{
    return new Tree(*this);
}