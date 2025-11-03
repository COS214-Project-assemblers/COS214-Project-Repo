/**
 * @file SalesFloor.h
 * @brief Sales floor management for customer interactions and plant sales
 */
#ifndef SALESFLOOR_H
#define SALESFLOOR_H

#include "Inventory.h"
#include "TransactionHistory.h"
#include "Ledger.h"

#include <vector>
#include <random>
#include <stdexcept>

class Customer;
class CustomerVisitor;

/**
 * @class SalesFloor
 * @brief Manages customer flow and provides access to inventory for sales interactions
 * 
 * The SalesFloor class provides the environment where customers interact with the manager
 * during sales. It maintains inventory access, financial ledger, and transaction history
 * for sales operations.
 * 
 * @see Inventory
 * @see Ledger
 * @see TransactionHistory
 * @see Manager
 */
class SalesFloor{
    private:
        Inventory* inv;              ///< Pointer to plant inventory
        Ledger ledger;               ///< Financial ledger for sales transactions
        TransactionHistory* history; ///< Transaction history recording

    public:
        /**
         * @brief Default constructor.
         */
        SalesFloor();

        /**
         * @brief Default destructor.
         */
        ~SalesFloor();
        
        /**
         * @brief Provides read-only access to inventory
         * @return Constant pointer to the Inventory object
         */
        const Inventory* inventory()const;

        /**
         * @brief Provides mutable access to inventory for manager operations
         * @return Mutable reference to the Inventory object
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
         * @brief Adds plant to sales floor inventory
         * @param p Pointer to Plant to add
         */
        void addPlant(Plant* p);

        /**
         * @brief Gets plant from sales floor by ID
         * @param id Plant identifier
         * @return Pointer to Plant if found, nullptr otherwise
         */
        Plant* getPlantOnSalesFloor(string id);

        /**
         * @brief Removes plant from sales floor by ID
         * @param id Plant identifier
         * @return Pointer to removed Plant
         */
        Plant* removePlantFromSalesFloor(string id);
};

#endif