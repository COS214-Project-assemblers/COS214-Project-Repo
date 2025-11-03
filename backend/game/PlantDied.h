/**
 * @file PlantDied.h
 * @brief Transaction strategy for plant death events
 */
#ifndef PLANTDIED_H
#define PLANTDIED_H

#include "TransactionStrategy.h"
#include <string>

/**
 * @class PlantDied
 * @brief Handles financial transactions when plants die due to poor care
 * @details Implements TransactionStrategy for deducting plant value when
 * plants die from lack of proper care.
 * 
 * @see TransactionStrategy
 */
class PlantDied:public TransactionStrategy{
    public:
        /**
         * @brief Default constructor.
         */
        PlantDied()=default;

        /**
         * @brief Default destructor
         */
        ~PlantDied()=default;

        /**
         * @brief Executes plant death transaction logic
         * @param v Value of the plant that died
         * @param b Current balance before transaction
         * @return New balance after deducting plant value (b - v)
         */
        double execute(double v, double b) override;

        /**
         * @brief Gets the transaction type identifier
         * @return "PlantDied" string
         */
        std::string getType()const override;
};
#endif