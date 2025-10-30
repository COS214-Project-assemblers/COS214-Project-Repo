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

#include <vector>
#include <string>
#include <algorithm>
#include <nlohmann/json.hpp>
using json=nlohmann::json;

class Plant;
class Customer;

class Manager{
    private:
        SalesFloor* floor;///<Reference to salesFloor object that is managed by the Manager.
        Ledger ledger;///<Ledger to keep track of balance
        // Transaction t;///<Transaction
        TransactionHistory hist;///<Transaction history to keep track of transactions
    public:
        /**
         * @brief Constructs a Manager associated with a given SalesFloor.
         * @param f Reference to the SalesFloor instange the Manager overseads.
         */
        explicit Manager();
        /**
         * @brief Deafult destructer
         */
        ~Manager()=default;
        /**
         * @brief Presents the builded offer of plants.
         * @param cust Reference to the customer being created.
         * @return True if offer leads to sale, false if not.
         */
        bool offerPlants(Customer& cust);
        /**
         * @brief Records a successful sale.
         * @param p The plant that was sold.
         */
        void recordSale(Plant& p);
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
         */
        void processReturns(Plant& p);
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
        void setTransaction(Transaction& t);
        /**
         * @brief getter for transaction
         * @return reference to transaction
         */
        Transaction& getTransaction();
        /**
         * @brief make offer to json
         * @param cust customer being offered to
         * @param diff difficulty level of game
         * @return json object containing offer data
         */
        json offerAsJSON(Customer& cust, const std::string diff);
        /**
         * @brief handle selection from user
         * @param cust customer making selection
         * @param choice index of plant chosen from offer
         * @return json object containing user choice?
         */
        json handleSelection(Customer& cust, int choice);

        const Inventory* getSaleInventory();
};

#endif