/**
 * @file Transaction.h
 * @brief Represents a financial transaction in the system
 */
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "TransactionStrategy.h"
#include "Sale.h"
#include "Return.h"
#include "Restock.h"
#include "TransactionMem.h"
#include "Ledger.h"
#include <string>
#include <stdexcept>

/**
 * @class Transaction
 * @brief Represents a single financial transaction with strategy and value
 * @details Encapsulates transaction data and behavior, using TransactionStrategy
 * to handle different transaction types (sale, return, restock, etc.).
 * 
 * @see TransactionStrategy
 * @see TransactionMem
 */
class Transaction{
    private:
        TransactionStrategy* tS;  ///< Pointer to TransactionStrategy for this transaction
        double value{0.0};        ///< Monetary value of the transaction
        int transID{0};           ///< Unique identifier for the transaction

    public:
        /**
         * @brief Constructor - creates transaction with strategy and value
         * @param tS Pointer to TransactionStrategy defining transaction behavior
         * @param v Monetary value of the transaction
         */
        Transaction(TransactionStrategy* tS,double v);

        /**
         * @brief Default destructor
         */
        ~Transaction() = default;

        /**
         * @brief Applies the transaction to a ledger and returns a snapshot
         * @param ledger Reference to current Ledger
         * @param plant Plant item from transaction
         * @return A TransactionMem snapshot
         */
        TransactionMem createTransactionMem(Ledger& ledger,Plant* plant)const;

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
        
        /**
         * @brief getter for transaction ID
         * @return transaction ID
         */
        int getTransactionID() const;
};
#endif