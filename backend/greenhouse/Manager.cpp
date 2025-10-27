#include "Manager.h"
#include "Customer.h"
#include "IgnorantCustomer.h"
#include "AverageCustomer.h"
#include "GreenFingerCustomer.h"

Manager::Manager(SalesFloor& f):floor(f){}

void Manager::difficultyMix(Customer& cust,int& e,int& m, int& h){
    if(dynamic_cast<const IgnorantCustomer*>(&cust)){
        e=3;
        m=1;
        h=1;
        return;
    }
    if(dynamic_cast<const AverageCustomer*>(&cust)){
        e=2;
        m=2;
        h=1;
        return;
    }
    //deafult to GreenFinger
    e=4;
    m=0;
    h=1;
}

std::vector<Plant*> Manager::buildOffer(const Customer& cust){
    //need to impliment
}

bool Manager::offerPlants(Customer& cust){
    //if successful offer move to hist, otherwise move to back of queue if decide to return process return and move to hist
    //need to impliment
}

bool Manager::assistNextCust(){
    if(!floor.hasCustomers()){
        return false;
    }
    Customer* c=floor.frontCust();
    offerPlants(*c);
    return true;
}

void Manager::recordSale(Customer& cust, Plant& p,double revenue){
    //need to impliment

}

void Manager::recordLostSale(Customer& cust,std::string reason){
    //need to impliment

}
