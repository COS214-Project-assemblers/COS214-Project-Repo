#ifndef SALE_H
#define SALE_H

#include "TransactionStrategy.h"
#include <string>

class Sale:public TransactionStrategy{
    public:
        Sale();
        ~Sale();
        double execute(double v, double b) override;
        std::string getType();
};
#endif