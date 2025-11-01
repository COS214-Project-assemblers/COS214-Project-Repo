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
        double value;///<Value of the transaction
        double balanceB4;///<value of balance befoe transaction
        double balanceAfter;///<Value of balance after Transaction
        std::string type;///<Type of transaction
        Plant* plant;///<Plant from transaction
        int tranID;///<Unique ID for transaction
        int retID;///<Default is -1, otherwise represents the transactionID from previous sale of return
    public:
        /**
         * @brief Constructor
         * @param t Type of Transaction
         * @param v Value of Transaction
         * @param b4 Balance before Transactrion was commited
         * @param after Balance after Transaction was commited
         * @param p Plant from Transaction
         * @param tID Transaction ID
         * @param retID ReturnedID for reference
         */
        TransactionMem(std::string t,double v,double b4, double after, Plant* p, int tID,int retID=-1);
        /**
         * @brief Default constructor
         */
        ~TransactionMem()=default;
        /**
         * @brief Getter of Value
         * @return Value of the Transaction
         */
        double getValue()const;
        /**
         * @brief Getter for balance before the Transaction
         * @return balance before the Transaction was executed
         */
        double getBalanceB4()const;
        /**
         * @brief Getter for balance after the Transaction
         * @return balance after the Transaction was executed
         */
        double getBalenceAfter()const;
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