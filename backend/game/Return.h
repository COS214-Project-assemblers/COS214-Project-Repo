/**
 * @file Return.h
 */
#ifndef RETURN_H
#define RETURN_H

#include "TransactionStrategy.h"
#include <string>

/**
 * @class Return
 * @brief Will handle the transaction as a Return
 */
class Return:public TransactionStrategy{
    public:
        /**
         * @brief Default constructor.
         */
        Return();
        /**
         * @brief Deconstructor.
         */
        ~Return();
        /**
         * @brief Executes a transactions financial logic to update the balance.
         * @param v Value of the transaction.
         * @param b Value of the current balance
         * @return THe new balance of b-v
         */
        double execute(double v, double b) override;
        /**
         * @brief Returns the Type of the transaction as a Return
         * @return "Return"
         */
        std::string getType();
};
#endif