/**
 * @file PlantDied.h
 */
#ifndef PLANTDIED_H
#define PLANTDIED_H

#include "TransactionStrategy.h"
#include <string>

/**
 * @class PlantDied
 * @brief Will handle the transaction as if a plant died after it was not cared for properly
 */
class PlantDied:public TransactionStrategy{
    public:
        /**
         * @brief Default constructor.
         */
        PlantDied();
        /**
         * @brief Deconstructor.
         */
        ~PlantDied();
        /**
         * @brief Executes a transactions financial logic to update the balance.
         * @param v Value of the transaction.
         * @param b Value of the current balance
         * @return THe new balance of b-v
         */
        double execute(double v, double b) override;
        /**
         * @brief Returns the Type of the transaction as a plant Died
         * @return "PlantDied"
         */
        std::string getType();
};
#endif