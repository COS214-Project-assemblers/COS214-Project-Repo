#include "Manager.h"
#include "Customer.h"
#include "IgnorantCustomer.h"
#include "AverageCustomer.h"
#include "GreenFingerCustomer.h"

Manager::Manager(SalesFloor& f):floor(f){}

void Manager::addRandomPlants(std::vector<Plant*>& source, int count, std::vector<Plant*>& offerList){
    if(source.empty()){
        return;
    }
    std::random_shuffle(source.begin(),source.end());
    for(int i=0;i<count && i<(int)source.size();i++){
        offerList.push_back(source[i]);
    }
}

std::vector<Plant*> Manager::buildOffer(const Customer& cust){
    //use inventory find by difficulty func to generate vectors of "easy","medium", and "hard" plants
    std::vector<Plant*> easy=floor.inventory().findByDifficulty("Easy");
    std::vector<Plant*> medium=floor.inventory().findByDifficulty("Medium");
    std::vector<Plant*> hard=floor.inventory().findByDifficulty("Hard");
    //vector of offers
    std::vector<Plant*> offer;
    if(dynamic_cast<const IgnorantCustomer*>(&cust)){
        addRandomPlants(easy,3,offer);
        addRandomPlants(medium,1,offer);
        addRandomPlants(hard,1,offer);
    }else if(dynamic_cast<const AverageCustomer*>(&cust)){
        addRandomPlants(easy,2,offer);
        addRandomPlants(medium,2,offer);
        addRandomPlants(hard,1,offer);
    }else{
        addRandomPlants(easy,4,offer);
        addRandomPlants(hard,1,offer);

    }
    return offer;
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
