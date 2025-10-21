/**
 * @file Transaction.h
 */
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "TransactionStrategy.h"
#include "TransactionMem.h"
#include <string>

/**
 * @class Transaction
 * @brief Represensts a single transaction in the system and holds its value and the TransactionStrategy used.
 */
class Transaction{
    private:
        TransactionStrategy* tS;///<Pointer to a Transaction Strategy object
        double value;///<Value of transaction
        double balance;///<Value of the current Balance
    public:
        /**
         * @brief Constructor
         * @param tS Pointer to a TransactionStrategy
         * @param v Value of the current Transaction
         */
        Transaction(TransactionStrategy* tS,double v);
        /**
         * @brief Deconstructor
         */
        ~Transaction();
        /**
         * @brief Creates a memento snapshot of this Transaction
         * @return A new TransactionMem
         */
        TransactionMem createTransactionMem();
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
         * @brief Getter for balance
         * @return Balance of transaction
         */
        double getBalance() const;
        /**
         * @brief Getter for type of transaction
         * @return the type of transaction e.g "Sale"
         */
        std::string getType() const;
};
#endif