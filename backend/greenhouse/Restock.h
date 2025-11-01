#ifndef RESTOCK_H
#define RESTOCK_H

#include "TransactionStrategy.h"
#include <string>

class Restock:public TransactionStrategy{
    public:
        Restock();
        ~Restock();
        double execute(double v, double b) override;
        std::string getType() const;
};
#endif