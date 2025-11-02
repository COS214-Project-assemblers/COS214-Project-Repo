#include "SalesFloor.h"

SalesFloor::SalesFloor(){
    inv = new Inventory();
}

SalesFloor::~SalesFloor()
{
    if(inv)
    {
        delete inv;
    }
}

void SalesFloor::add(Customer* cust){
    customers.push_back(cust);
}

void SalesFloor::moveToCustHist(Customer* cust){
    if(!cust){
        return;
    }
    auto i=std::find(customers.begin(),customers.end(),cust);
    if(i!=customers.end()){
        customers.erase(i);
    }
    custHist.push_back(cust);
}

bool SalesFloor::hasCustomers(){
    return !this->customers.empty();
}

Customer* SalesFloor::frontCust(){
    if(customers.empty()){
        return NULL;
    }
    return customers.front();
}

Customer* SalesFloor::popCust(){
    if(customers.empty()){
        return NULL;
    }
    Customer* first=customers.front();
    customers.erase(customers.begin());
    return first;
}

const Inventory* SalesFloor::inventory()const{
    if(!this->inv){
        throw std::runtime_error("SalesFloor::inventory() called before inventory is set");
    }
    return this->inv;
}

Inventory& SalesFloor::inventoryMut(){
    if(!this->inv){
        throw std::runtime_error("SalesFloor::inventory() called before inventory is set");
    }
    return *this->inv;
}

Ledger& SalesFloor::getLedger(){
    return this->ledger;
}

const Ledger& SalesFloor::getLedger()const{
    return this->ledger;
}

void SalesFloor::addPlant(Plant* p)
{
    inv->restock(p);
}

Plant* SalesFloor::getPlantOnSalesFloor(string id)
{
    return inv->getPlant(id);
}