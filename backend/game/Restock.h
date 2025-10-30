/**
 * @file Restock.h
 */
#ifndef RESTOCK_H
#define RESTOCK_H

#include "TransactionStrategy.h"
#include <string>

/**
 * @class Restock
 * @brief Will handle the transaction as a refund
 */
class Restock:public TransactionStrategy{
    public:
        /**
         * @brief Default constructor.
         */
        Restock()=default;
        /**
         * @brief Deconstructor.
         */
        ~Restock()=default;
        /**
         * @brief Executes a transactions financial logic to update the balance.
         * @param v Value of the transaction.
         * @param b Value of the current balance
         * @return THe new balance of b-v
         */
        double execute(double v, double b) override;
        /**
         * @brief Returns the Type of the transaction as a Restock
         * @return "Restock"
         */
        std::string getType()const override;
};
#endif