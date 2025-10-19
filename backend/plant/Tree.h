#ifndef TREE_H
#define TREE_H

#include "Plant.h"

class Tree : public Plant
{
    public:
        Tree(string variety);
        ~Tree();

        Plant* clone();
};

#endif