#ifndef SALESFLOOR_H
#define SALESFLOOR_H

#include "Inventory.h"
#include "Customer.h"

#include <vector>

class SalesFloor{
    private:
        Inventory* inventory;
        std::vector<Customer*> customers;
        std::vector<Customer*> custHist;
    public:
        SalesFloor();
        ~SalesFloor()=default;
        void add(Customer* cust);
        void moveToCustHist(Customer* cust);
        void accept(CustomerVisitor& v);
        bool hasCustomers();
        Customer* frontCust();
        Customer* popCust();
        const Inventory& inventory();
        void processReturns(double prob);
};

#endif