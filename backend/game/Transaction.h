/**
 * @file Transaction.h
 */
#ifndef TRANSACTION_H
#define TRANSACTION_H

// #include "TransactionStrategy.h"
#include "Sale.h"
#include "Return.h"
#include "Restock.h"
#include "TransactionMem.h"
#include "Ledger.h"
#include <string>
#include <stdexcept>

/**
 * @class Transaction
 * @brief Represensts a single transaction in the system and holds its value and the TransactionStrategy used.
 */
class Transaction{
    private:
        TransactionStrategy* tS;///<Pointer to a Transaction Strategy object
        double value;///<Value of transaction
    public:
        /**
         * @brief Constructor
         * @param tS Pointer to a TransactionStrategy
         * @param v Value of the current Transaction
         */
        Transaction(TransactionStrategy* tS,double v);
        /**
         * @brief Default Deconstructor
         */
        ~Transaction()=default;
        /**
         * @brief Applies the transaction to a ledger and returns a snapshot
         * @param ledger Reference to current Ledger
         * @param plant Plant item from transaction
         * @return A TransactionMem snapshot
         */
        TransactionMem createTransactionMem(Ledger& ledger,Plant* plant)const;
        /**
         * @brief Restores the Transaction From memento
         * @param tM TransacionMem obj
         */
        void setTransactionMem(const TransactionMem tM);
        /**
         * @brief Getter for Value
         * @return Value of transaction
         */
        double getValue() const;
        /**
         * @brief Getter for type of transaction
         * @return the type of transaction e.g "Sale"
         */
        std::string getType() const;
};
#endif