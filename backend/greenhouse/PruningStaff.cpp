#include "PruningStaff.h"
#include "Plant.h"
#include "Sellable.h"
#include "Greenhouse.h"

void PruningStaff::update(const string &careType, Plant *plant) {


    plant->setState(new Sellable()); // could immediately progress to Sellable,                               // because if a plant needs pruning it's pretty much mature?
            if (greenhouse != nullptr) {
                greenhouse->movePlant(plant);
            } else {
                cout << "Staff not attached to greenhouse" << endl;
            }
}

/*
Example:

PruningStaff: Pruning Apple Tree (Tree)...

*/
