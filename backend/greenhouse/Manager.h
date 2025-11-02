/**
 * @class Manager
 * @brief Declares manager class which is responsible for managing the creation of plant offers, and dealing with customers through the sales floor. 
 * 
 * The Manager class coordinates the interactions between the sales floor and customers.
 * It builds Plant offers for the customers, and processes the transactions (recorded/lost)
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
// #include <nlohmann/json.hpp>
// using json=nlohmann::json;

class Plant;
class Customer;

class Manager{
    private:
        SalesFloor* floor;///<Reference to salesFloor object that is managed by the Manager.
        Ledger ledger;///<Ledger to keep track of balance
        TransactionStrategy* strat;
        TransactionHistory hist;///<Transaction history to keep track of transactions
        Greenhouse* greenhouse;
    public:
        /**
         * @brief Constructs a Manager associated with a given SalesFloor.
         * @param f Reference to the SalesFloor instange the Manager overseads.
         */
        explicit Manager();
        /**
         * @brief Deafult destructer
         */
        ~Manager();
        /**
         * @brief Records a successful sale.
         * @param p The plant that was sold.
         */
        void recordSale(string id);
        /**
         * @brief Records if a sale was lost with the rason as to why.
         * @param cust The Customer to which a sale was lost.
         * @param p The plant that was offered but was declined
         */
        void recordRestock(Plant& p);
        /**
         * @brief records if a plant died in the greenhouse
         * @param p The plant that died
         */
        void recordPlantDied(Plant& p);
        /**
         * @brief record return of plant
         * @param p The plant being returned
         * @return true if return was executed, false if not
         */
        bool processReturns(Plant& p);
        /**
         * @brief Getter for inventory
         * @return Reference to the inventory managed by the salesFloor
         */
        const Inventory* inventory()const;
        /**
         * @brief Mutable getter for inventory
         * @return Mutable reference to the inventory managed by the salesFloor
         */
        Inventory& inventoryMut();
        /**
         * @brief set transaction
         * @param t transaction to set
         */

        const Inventory* getSaleInventory();

        float getBalance();
        void resetBalance();
        TransactionHistory getTransactionHist()const;

        void setGreenhouse(Greenhouse* greenhouse);
};

#endif