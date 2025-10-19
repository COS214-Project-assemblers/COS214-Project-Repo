#ifndef PLANTDIED_H
#define PLANTDIED_H

#include "TransactionStrategy.h"
#include <string>

class PlantDied:public TransactionStrategy{
    public:
        PlantDied();
        ~PlantDied();
        double execute(double v, double b) override;
        std::string getType();
};
#endif