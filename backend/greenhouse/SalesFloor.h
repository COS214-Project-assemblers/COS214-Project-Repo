/**
 * @file SalesFloor.h
 */
#ifndef SALESFLOOR_H
#define SALESFLOOR_H

#include "Inventory.h"
#include "Customer.h"

#include <vector>
#include <stdexcept>
/**
 * @class SalesFloor
 * @brief Manages Customer flow and provides access to the inventory for the Manager during sales interactions.
 * 
 * The SalesFloor class is for the enviroment in which the Customer can interact with the Manager. It maintains a current "queue" and history lists.
 */
class SalesFloor{
    private:
        Inventory* inv;///<Pointer to Inventory object
        std::vector<Customer*> customers;///<Vector of customers in the "queue"
        std::vector<Customer*> custHist;///<Vector of customers that have moved out of the "queue" and is just a history
    public:
        /**
         * @brief Default constructor.
         */
        SalesFloor();
        /**
         * @brief Default deconstructor.
         */
        ~SalesFloor()=default;
        /**
         * @brief Adds a Customer to the customers vector (queue).
         * @param cust Reference to the customer being added to the "queue".
         * 
         * Will also move a customer to the back of the queue if it they decide to return their product at hte end of the transaction.
         */
        //ally - maybe and also add them back if we offer like would you like more options?
        void add(Customer* cust);
        /**
         * @brief Will remove a costomer from the customers vector to the custHist vector to keep track of customers served.
         * @param cust The customer who has made a desion(purchase a plant/or not) and is moving to history
         */
        void moveToCustHist(Customer* cust);
        //name might change
        void accept(CustomerVisitor& v);
        /**
         * @brief checks if there are custoemrs in the queue.
         * @return True if there are customers in the "queue", False if not.
         */
        //Ally -  will be used to help the manager see if it can move to the next customer or maybe if the game has ended or it goes to the greenhouse view?
        bool hasCustomers();
        /**
         * @brief Tells you who the customer at the front of the "queue" is.
         * @return pointer to the Customer
         */
        Customer* frontCust();
        /**
         * @brief Removes the customer at the front of the "queue" after they have been helped/or decided to return their plant
         * @return pointer to the Customer
         */
        Customer* popCust();
        /**
         * @brief Provides read only access to the Manager
         * @return Constant reference to the Inventory object managed by the salesFloor.
         */
        const Inventory& inventory()const;
        /**
         * @brief Simulates the process of returns based on a given probability.
         * @param prob Probability that a customer decides to return a product.
         */
        //Ally - could maybe also use visitor for this to return the probabilty based on the type of customer.
        void processReturns(double prob);
};

#endif