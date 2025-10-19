#ifndef TRANSACTIONSTRATEGY_H
#define TRANSACTIONSTRATEGY_H

#include <string>

class TransactionStrategy{
    public:
        TransactionStrategy();
        virtual ~TransactionStrategy();
        virtual double execute(double v, double b)=0;
        virtual std::string getType()=0;
};
#endif