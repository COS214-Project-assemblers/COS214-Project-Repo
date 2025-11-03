/**
 * @file SalesFloor.h
 */
#ifndef SALESFLOOR_H
#define SALESFLOOR_H

#include "Inventory.h"
// #include "Customer.h"
#include "TransactionHistory.h"
#include "Ledger.h"

#include <vector>
#include <random>
#include <stdexcept>

class Customer;
class CustomerVisitor;

/**
 * @class SalesFloor
 * @brief Manages Customer flow and provides access to the inventory for the Manager during sales interactions.
 * 
 * The SalesFloor class is for the enviroment in which the Customer can interact with the Manager. It maintains a current "queue" and history lists.
 */
class SalesFloor{
    private:
        Inventory* inv;///<Pointer to Inventory object
        Ledger ledger;///<Ledger to keep track of balance
        TransactionHistory* history;
    public:
        /**
         * @brief Default constructor.
         */
        SalesFloor();
        /**
         * @brief Default deconstructor.
         */
        ~SalesFloor();
        
        /**
         * @brief Provides read only access
         * @return Constant reference to the Inventory object managed by the salesFloor.
         */
        const Inventory* inventory()const;
        /**
         * @brief non-const access for manager.
         * @return returns mutateable ref to Inventory.
         */
        Inventory& inventoryMut();
        /**
         * @brief Mutable getter for the ledger
         * @return Reference to the ledger object
         */
        Ledger& getLedger();
        /**
         * @brief Read only getter for the ledger
         * @return Constant reference to the ledger object
         */
        const Ledger& getLedger()const;
        /**
         * @brief Simulates the process of returns based on a given probability.
         * @param prob Probability that a customer decides to return a product.
         * @param hist Reference to the TransactionHistory to process returns.
         */

        void addPlant(Plant* p);

        Plant* getPlantOnSalesFloor(string id);
        Plant* removePlantFromSalesFloor(string id);
};

#endif