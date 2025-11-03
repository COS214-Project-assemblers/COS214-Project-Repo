/**
 * @file Return.h
 * @brief Transaction strategy for return operations
 */
#ifndef RETURN_H
#define RETURN_H

#include "TransactionStrategy.h"
#include <string>

/**
 * @class Return
 * @brief Handles financial transactions for customer returns
 * @details Implements TransactionStrategy for processing refunds when
 * customers return plants.
 * 
 * @see TransactionStrategy
 */
class Return : public TransactionStrategy{
    public:
        /**
         * @brief Default constructor.
         */
        Return()=default;

        /**
         * @brief Default destructor
         */
        ~Return()=default;

        /**
         * @brief Executes return transaction logic
         * @param v Refund amount for returned plant
         * @param b Current balance before transaction
         * @return New balance after refund (b - v)
         */
        double execute(double v, double b) override;

        /**
         * @brief Gets the transaction type identifier
         * @return "Return" string
         */
        std::string getType()const override;
};
#endif