/**
 * @file Restock.h
 * @brief Transaction strategy for restock operations
 */
#ifndef RESTOCK_H
#define RESTOCK_H

#include "TransactionStrategy.h"
#include <string>

/**
 * @class Restock
 * @brief Handles financial transactions for inventory restocking
 * @details Implements TransactionStrategy for deducting costs when
 * purchasing new plants for inventory.
 * 
 * @see TransactionStrategy
 */
class Restock : public TransactionStrategy{
    public:
        /**
         * @brief Default constructor.
         */
        Restock()=default;

        /**
         * @brief Default destructor
         */
        ~Restock()=default;

        /**
         * @brief Executes restock transaction logic
         * @param v Cost of plants being restocked
         * @param b Current balance before transaction
         * @return New balance after restock cost (b - v)
         */
        double execute(double v, double b) override;

        /**
         * @brief Gets the transaction type identifier
         * @return "Restock" string
         */
        std::string getType()const override;
};
#endif