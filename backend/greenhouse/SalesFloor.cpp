#include "SalesFloor.h"

SalesFloor::SalesFloor(){
    this->inv=NULL;
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

Ledger& SalesFloor::getLedger(){
    return this->ledger;
}

const Ledger& SalesFloor::getLedger()const{
    return this->ledger;
}

void SalesFloor::processReturns(double prob,TransactionHistory& hist){
    //need to impliment
    //if user chooses correct plant, no return
    //if not there is a probability they return it
    if(prob<=0.0){
        return;
    }
    if(prob>1){
        prob=1;
    }
    if(!this->inv){
        throw std::runtime_error("SalesFloor::processReturns() called before inventory is set");
    }
    //random roll
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double roll=dis(gen);
    //checks if cust decided to return
    if(roll<prob){
        //customer decided to return a plant therefore undo last transaction
        bool success=hist.processReturn(this->ledger,*this->inv);
    }
}

std::vector<Plant*> SalesFloor::findByDifficulty(std::string d)const{
    std::vector<Plant*> out;
    for(auto* p:this->inv){
        if(p->getDifficulty()==d){
            out.push_back(p);
        }
    }
    return out;
}