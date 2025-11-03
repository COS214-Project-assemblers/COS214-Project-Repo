/**
 * @file Sale.h
 * @brief Transaction strategy for sales operations
 */
#ifndef SALE_H
#define SALE_H

#include "TransactionStrategy.h"
#include <string>

/**
 * @class Sale
 * @brief Handles financial transactions for plant sales
 * @details Implements TransactionStrategy for processing income from
 * customer plant purchases.
 * 
 * @see TransactionStrategy
 */
class Sale : public TransactionStrategy{
    public:
        /**
         * @brief Default constructor
         */
        Sale()=default;

        /**
         * @brief Default destructor
         */
        ~Sale()=default;

        /**
         * @brief Executes sale transaction logic
         * @param v Sale price of the plant
         * @param b Current balance before transaction
         * @return New balance after sale (b + v)
         */
        double execute(double v, double b) override;

        /**
         * @brief Gets the transaction type identifier
         * @return "Sale" string
         */
        std::string getType()const override;
};
#endif