#ifndef TRANSACTIONMEM_H
#define TRANSACTIONMEM_H

#include "TransactionStrategy.h"
#include <string>

class TransactionMem{
    private:
        TransactionStrategy* tS;
        double value;
        double balance;
    public:
        TransactionMem(TransactionStrategy* tS,double v);
        ~TransactionMem();
        double getValue();
        double getBalance();
        std::string getType();
};
#endif