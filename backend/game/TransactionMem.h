/**
 * @file TransactionMem.h
 */
#ifndef TRANSACTIONMEM_H
#define TRANSACTIONMEM_H

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
    public:
        /**
         * @brief Constructor
         * @param t Type of Transaction
         * @param v Value of Transaction
         * @param b4 Balance before Transactrion was commited
         * @param after Balance after Transaction was commited
         */
        TransactionMem(std::string t,double v,double b4, double after);
        /**
         * @brief Default constructor
         */
        ~TransactionMem()=default;
        /**
         * @brief Getter of Value
         * @return Value of the Transaction
         */
        const double getValue()const;
        /**
         * @brief Getter for balance before the Transaction
         * @return balance before the Transaction was executed
         */
        const double getBalanceB4()const;
        /**
         * @brief Getter for balance after the Transaction
         * @return balance after the Transaction was executed
         */
        const double getBalenceAfter()const;
        /**
         * @brief Getter for type of transaction
         * @return the type of transaction e.g "Sale"
         */
        const std::string getType()const;
};
#endif