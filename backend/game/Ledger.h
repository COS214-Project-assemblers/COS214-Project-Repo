/**
 * @file ledger.h
 */
#ifndef LEDGER_H
#define LEDGER_H

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
};

#endif