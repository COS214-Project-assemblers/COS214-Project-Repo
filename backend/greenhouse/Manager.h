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

#include <vector>
#include <string>

class Plant;
class Customer;

class Manager{
    private:
        SalesFloor& floor;///<Reference to salesFloor object that is managed by the Manager.
    public:
        /**
         * @brief Constructs a Manager associated with a given SalesFloor.
         * @param f Reference to the SalesFloor instange the Manager overseads.
         */
        explicit Manager(SalesFloor& f);
        /**
         * @brief Deafult destructer
         */
        ~Manager()=default;
        /**
         * @brief Builds a list of plant offers based on this customer.
         * @param cust The customer for whom you are creating the offer.
         * @return A vector of Plant ptrs represnting the reccomended plants.
         */
        std::vector<Plant*> buildOffer(const Customer& cust);
        /**
         * @brief Presents the builded offer of plants.
         * @param cust Reference to the customer being created.
         * @return True if offer leads to sale, false if not.
         */
        bool offerPlants(Customer& cust);
        /**
         * @brief Assists next customer in the queue.
         * @return True if customer was successfully assisted, false if not.
         */
        bool assistNextCust();
        /**
         * @brief Records a successful sale.
         * @param cust The customer who made the purchase.
         * @param p The plant that was sold.
         * @param revenue The price the plant was sold for.
         */
        void recordSale(Customer& cust, Plant& p,double revenue);
        /**
         * @brief Records if a sale was lost with the rason as to why.
         * @param cust The Customer to which a sale was lost.
         * @param reason The rason as to why the customer didnt make the purchase
         */
        void recordLostSale(Customer& cust,std::string reason);
};

#endif