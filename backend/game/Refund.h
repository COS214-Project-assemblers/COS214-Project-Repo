#ifndef REFUND_H
#define REFUND_H

#include "TransactionStrategy.h"
#include <string>

class Refund:public TransactionStrategy{
    public:
        Refund();
        ~Refund();
        double execute(double v, double b) override;
        std::string getType();
};
#endif