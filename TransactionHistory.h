#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H

#include "TransactionMem.h"
#include <vector>

class TransactionHistory{
    private:
        std::vector<TransactionMem> memento;
    public:
        TransactionHistory();
        ~TransactionHistory();
        void setTransactionMem(TransactionMem tM);
        TransactionMem getTransactionMem();
        void print();
};
#endif