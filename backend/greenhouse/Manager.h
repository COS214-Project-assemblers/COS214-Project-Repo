#ifndef MANAGER_H
#define MANAGER_H

#include "SalesFloor.h"

#include <vector>
#include <string>

class Plant;
class Customer;

class Manager{
    private:
        SalesFloor& floor;
    public:
        explicit Manager(SalesFloor& f);
        ~Manager()=default;
        std::vector<Plant*> buildOffer(const Customer& cust);
        bool offerPlants(Customer& cust);
        bool assistNextCust();
        void recordSale(Customer& cust, Plant& p,double revenue);
        void recordLostSale(Customer& cust,std::string reason);
};

#endif