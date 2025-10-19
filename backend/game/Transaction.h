#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "TransactionStrategy.h"
#include "TransactionMem.h"
#include <string>

class Transaction{
    private:
        TransactionStrategy* tS;
        double value;
        double balance;
    public:
        Transaction(TransactionStrategy* tS,double v);
        ~Transaction();
        TransactionMem createTransactionMem();
        void setTransactionMem(TransactionMem tM);
        double getValue();
        double getBalance();
        std::string getType();
};
#endif