#include "SalesFloor.h"

SalesFloor::SalesFloor(){
    //need to impliment
    
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

// void SalesFloor::accept(CustomerVisitor& v){
//     if(customers.empty()){
//         return;
//     }
//     Customer* c=customers.front();
//     c->accept(v);
//     customers.erase(customers.begin());
//     custHist.push_back(c);
// }

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

const Inventory& SalesFloor::inventory()const{
    if(!this->inv){
        throw std::runtime_error("SalesFloor::inventory() called before inventory is set");
    }
    return *this->inv;
}

Inventory& SalesFloor::inventoryMut(){
    if(!this->inv){
        throw std::runtime_error("SalesFloor::inventory() called before inventory is set");
    }
    return *this->inv;
}

void SalesFloor::processReturns(double prob){
    //need to impliment
    if(prob<=0.0){
        return;
    }
    if(prob>1){
        prob=1;
    }

}
