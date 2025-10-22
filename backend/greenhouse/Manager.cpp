#include "Manager.h"

Manager::Manager(SalesFloor& f):floor(f){}

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
