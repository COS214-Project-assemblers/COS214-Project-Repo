/**
 * @file Ledger.h
 * @brief Financial ledger for tracking game balance
 */

#ifndef LEDGER_H
#define LEDGER_H

#include <nlohmann/json.hpp>
using json=nlohmann::json;

/**
 * @class Ledger
 * @brief Maintains and manages the game's financial balance
 * @details Provides balance tracking and JSON serialization capabilities
 * for financial state management.
 */
class Ledger{
    private:
        /**
         * @brief Current game balance
         */
        double balance;
        
    public:
        /**
         * @brief Constructor - initializes balance to zero
         */
        Ledger();

        /**
         * @brief Default destructor
         */
        ~Ledger()=default;

        /**
         * @brief Get current balance
         * @return Current balance as double
         */
        double getBalance();

        /**
         * @brief Set new balance value
         * @param newBal The updated balance value
         */
        void setBalance(double newBal);

        /**
         * @brief Convert balance to JSON format
         * @return JSON object containing balance information
         */
        json balToJSON()const;
};

#endif