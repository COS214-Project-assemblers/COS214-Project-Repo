/**
 * @file Manager.h
 * @brief Manager class for coordinating plant sales and customer interactions
 */

#ifndef MANAGER_H
#define MANAGER_H

#include "SalesFloor.h"
#include "Ledger.h"
#include "Transaction.h"
#include "Greenhouse.h"

#include <vector>
#include <string>
#include <algorithm>

class Plant;
class Customer;

/**
 * @class Manager
 * @brief Coordinates plant sales, customer interactions, and financial transactions
 * 
 * The Manager class is responsible for managing the creation of plant offers, 
 * dealing with customers through the sales floor, and processing financial 
 * transactions. It serves as the central coordinator between sales floor, 
 * greenhouse, and financial systems.
 * 
 * @see SalesFloor
 * @see Greenhouse
 * @see Ledger
 * @see TransactionHistory
 */
class Manager{
    private:
        SalesFloor* floor;           ///< Reference to sales floor for customer interactions
        Ledger ledger;               ///< Financial ledger for balance tracking
        TransactionStrategy* strat;  ///< Current transaction strategy
        TransactionHistory hist;     ///< Transaction history for reporting and refunds
        Greenhouse* greenhouse;      ///< Reference to greenhouse for plant operations

    public:
        /**
         * @brief Constructs a Manager with default initialization
         */
        explicit Manager();

        /**
         * @brief Destructor - cleans up manager resources
         */
        ~Manager();

        /**
         * @brief Records a successful sale.
         * @param p The plant that was sold.
         */
        void recordSale(string id);

        /**
         * @brief Records plant restocking transaction
         * @param p Reference to the Plant being restocked
         */
        void recordRestock(Plant& p);

        /**
         * @brief Records plant death in greenhouse
         * @param p Reference to the Plant that died
         */
        void recordPlantDied(Plant& p);

        /**
         * @brief Processes customer plant returns
         * @param p Reference to the Plant being returned
         * @return true if return was processed successfully, false otherwise
         */
        bool processReturns(Plant& p);

        /**
         * @brief Get read-only access to inventory
         * @return Constant pointer to the inventory managed by sales floor
         */
        const Inventory* inventory()const;

        /**
         * @brief Get mutable access to inventory
         * @return Mutable reference to the inventory managed by sales floor
         */
        Inventory& inventoryMut();

        /**
         * @brief Get sales floor inventory
         * @return Constant pointer to sales floor inventory
         */
        const Inventory* getSaleInventory();

        /**
         * @brief Get current balance
         * @return Current financial balance as float
         */
        float getBalance();

        /**
         * @brief Resets balance to 500
         */
        void resetBalance();

        /**
         * @brief Get transaction history
         * @return TransactionHistory object containing transaction records
         */
        TransactionHistory getTransactionHist()const;

        /**
         * @brief Sets greenhouse reference
         * @param greenhouse Pointer to Greenhouse instance
         */
        void setGreenhouse(Greenhouse* greenhouse);
};

#endif