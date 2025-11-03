/**
 * @file TransactionHistory.h
 * @brief Maintains history of financial transactions
 */
#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H

#include "TransactionMem.h"
#include "Ledger.h"
#include "Inventory.h"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <nlohmann/json.hpp>

class Inventory;

class TransactionHistory{
    private:
        std::vector<TransactionMem> memento;  ///< Vector storing transaction history snapshots

    public:
        /**
         * @brief Default Constructor
         */
        TransactionHistory()=default;

        /**
         * @brief Default destructor
         */
        ~TransactionHistory()=default;

        /**
         * @brief Adds a transactionMem to the history
         * @param tM The TransactionMem snapshot to add
         */
        void setTransactionMem(const TransactionMem& tM);

        /**
         * @brief Retrieves specific transaction snapshot by index
         * @param index Position of snapshot in vector
         * @return TransactionMem object at specified index
         */
        TransactionMem getTransactionMem(int index)const;

        /**
         * @brief Clears transaction History to start new day/reset
         */
        void clear();

        /**
         * @brief checks if a transaction ID has already been returned
         * @param tID Transaction ID to check
         * @return True if it has been returned, False if not
         */
        bool hasBeenReturned(int tID)const;

        /**
         * @brief Gives you the last transaction ID for a specific plant
         * @param p Plant pointer to check for
         * @return transaction ID if found, -1 if not found
         */
        int FindTransactionIDFor(const Plant* p)const;

        /**
         * @brief Prints daily transaction statement (primarily for testing)
         * @details Outputs formatted statement similar to bank statement
         * showing all daily transactions with types, values, and balances
         */
        void printStatement();

        /**
         * @brief Gives the statement for the day in JSON format for front end
         * @return A string of the JSON statement
         */
        std::string statementJSON()const;
};
#endif