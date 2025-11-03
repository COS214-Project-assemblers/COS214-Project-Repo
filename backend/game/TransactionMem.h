/**
 * @file TransactionMem.h
 */
#ifndef TRANSACTIONMEM_H
#define TRANSACTIONMEM_H

#include "Plant.h"

#include <string>

/**
 * @class TransactionMem
 * @brief The transactionMem class is used to create a snapshot of a transaction
 */
class TransactionMem{
    private:
        double value{0.0};           ///< Monetary value of the transaction
        double balanceB4{0.0};       ///< Balance before transaction was applied
        double balanceAfter{0.0};    ///< Balance after transaction was applied
        std::string type;            ///< Type of transaction (Sale, Return, etc.)
        Plant* plant;                ///< Plant involved in the transaction
        int tranID{0};               ///< Unique transaction identifier
        int retID;                   ///< Reference to original transaction ID for returns

    public:
        /**
         * @brief Constructor - creates complete transaction snapshot
         * @param t Type of transaction
         * @param v Monetary value
         * @param b4 Balance before transaction
         * @param after Balance after transaction
         * @param p Plant involved
         * @param tID Transaction ID
         * @param retID Return reference ID (default -1 for non-return transactions)
         */
        TransactionMem(std::string t,double v,double b4, double after, Plant* p, int tID,int retID=-1);

        /**
         * @brief Default constructor
         */
        ~TransactionMem()=default;

        /**
         * @brief Get transaction value
         * @return Monetary value of the transaction
         */
        double getValue()const;

        /**
         * @brief Get balance before transaction
         * @return Account balance before this transaction
         */
        double getBalanceB4()const;

        /**
         * @brief Getter for balance after the Transaction
         * @return balance after the Transaction was executed
         */
        double getBalanceAfter()const;

        /**
         * @brief Getter for type of transaction
         * @return the type of transaction e.g "Sale"
         */
        std::string getType()const;

        /**
         * @brief getter for plant from transaction
         * @return the plant from the transaction
         */
        Plant* getPlant()const;

        /**
         * @brief Getter for plant from transaction
         * @return the plant from the transaction
         */
        int getTransactionID()const;

        /**
         * @brief Setter for the transactionID from previous sale of return
         * @param tID The reference id of the previous sale id
         */
        void setReturnedID(int tID);
        
        /**
         * @brief Gerrter for the returnID
         * @return The returned ID
         */
        int getReturnedID()const;
};
#endif