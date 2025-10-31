/**
 * @file TransactionHistory.h
 */
#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H

#include "TransactionMem.h"
#include "Ledger.h"
#include "Inventory.h"

#include <iostream>
#include <vector>
#include <stdexcept>

class Inventory;

/**
 * @class TransactionHistory
 * @brief Stores Mememntos that allows for processing refunds and printing the transaction history at end of day
 */
class TransactionHistory{
    private:
        std::vector<TransactionMem> memento;///<Vector to store the history of the transactions
        std::vector<int> returnedIDs;///<Vector of the returned IDs for transactions
    public:
        /**
         * @brief Default Constructor
         */
        TransactionHistory()=default;
        /**
         * @brief Deafult deconstructor
         */
        ~TransactionHistory()=default;
        /**
         * @brief Adds a transactionMem to the history
         * @param tM The TransactionMem snapshot to add
         */
        void setTransactionMem(const TransactionMem& tM);
        /**
         * @brief retireves a specific snapshot by index
         * @param index Index of snapshot in memento vector
         * @return The TransactionMem object at that index
         */
        TransactionMem getTransactionMem(int index)const;
        /**
         * @brief Print the whole transaction history from that day.
         */
        void print()const;
        /**
         * @brief Undo last transaction to process Refund
         * @param l Reference to the ledger object to modify
         * @return True if undo succeed, False if not.
         */
        bool processReturn(Ledger& l,Inventory& inv);
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
         * @brief marks a transaction ID as returned
         * @param tID Transaction ID to mark as returned
         */
        void markAsReturned(int tID);
        /**
         * @brief Gives you the last transaction ID for a specific plant
         * @param p Plant pointer to check for
         * @return transaction ID if found, -1 if not found
         */
        int FindTransactionIDFor(const Plant* p)const;
};
#endif