/**
 * @file Sale.h
 */
#ifndef SALE_H
#define SALE_H

#include "TransactionStrategy.h"
#include <string>

/**
 * @class Sale
 * @brief Will handle the transaction as a sale
 */
class Sale:public TransactionStrategy{
    public:
        /**
         * @brief Default constructor
         */
        Sale();
        /**
         * @brief Deconstructor
         */
        ~Sale();
        /**
         * @brief Executes a transactions financial logic to update the balance.
         * @param v Value of the transaction.
         * @param b Value of the current balance
         * @return THe new balance of b+v
         */
        double execute(double v, double b) override;
        /**
         * @brief Returns the Type of the transaction as a Sale
         * @return "Sale"
         */
        std::string getType();
};
#endif