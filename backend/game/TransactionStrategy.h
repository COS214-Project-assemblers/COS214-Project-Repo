/**
 * @file TransactionStrategy.h
 */
#ifndef TRANSACTIONSTRATEGY_H
#define TRANSACTIONSTRATEGY_H

#include <string>

/**
 * @class TransactionStrategy
 * @brief The TransactionStrategy class an abstract class that will help define how transactions will be handeld based on the type of Transaction.
 */
class TransactionStrategy{
    public:
        /**
         * @brief default constructor.
         */
        TransactionStrategy();
        /**
         * @brief Virtual Deconstructor.
         */
        virtual ~TransactionStrategy();
        /**
         * @brief Executes a transactions financial logic to update the balance.
         * @param v Value of the transaction.
         * @param b Value of the current balance
         * @return THe new balance after a transaction has been executed.
         */
        virtual double execute(double v, double b)=0;
        /**
         * @brief Returns the Type of the transaction
         * @return The Type of the transaction
         */
        virtual std::string getType()=0;
};
#endif