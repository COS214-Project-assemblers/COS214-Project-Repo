/**
 * @file ledger.h
 */
#ifndef LEDGER_H
#define LEDGER_H

#include <nlohmann/json.hpp>
using json=nlohmann::json;

/**
 * @class Ledger
 * @brief Holds the balance
 */
class Ledger{
    private:
        double balance;///<Balance variable
    public:
        /**
         * @brief Construstor
         */
        Ledger();
        /**
         * @brief default deconstructor
         */
        ~Ledger()=default;
        /**
         * @brief Getter for Balance
         * @return current balance
         */
        double getBalance();
        /**
         * @brief Setter for balance
         * @param newBal the updated balance based on the transactionStrategy Calc
         */
        void setBalance(double newBal);
        /**
         * @brief converst balance to json
         * @return json object containing balance info
         */
        json balToJSON()const;
};

#endif