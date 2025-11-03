/**
 * @file TransactionStrategy.h
 * @brief Abstract base class for transaction strategies
 */
#ifndef TRANSACTIONSTRATEGY_H
#define TRANSACTIONSTRATEGY_H

#include <string>

/**
 * @class TransactionStrategy
 * @brief Abstract base class for transaction handling strategies
 * @details Defines the interface for different transaction types using
 * the Strategy pattern. Each concrete strategy implements specific
 * financial logic for different transaction types (sale, return, etc.).
 * 
 * @see Sale
 * @see Return
 * @see Restock
 * @see PlantDied
 */
class TransactionStrategy{
    public:
        /**
         * @brief Default constructor
         */
        TransactionStrategy();

        /**
         * @brief Virtual destructor for proper polymorphic cleanup
         */
        virtual ~TransactionStrategy();

        /**
         * @brief Executes transaction financial logic
         * @param v Monetary value of the transaction
         * @param b Current balance before transaction
         * @return New balance after transaction processing
         */
        virtual double execute(double v, double b)=0;

        /**
         * @brief Gets transaction type identifier
         * @return Transaction type string
         */
        virtual std::string getType()const =0;
};
#endif