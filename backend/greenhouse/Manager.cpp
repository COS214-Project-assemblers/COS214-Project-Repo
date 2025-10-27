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

void Manager::topUpRandomPlants(const std::vector<Plant*>& source, int need, std::vector<Plant*>& offerList){
    if(need<=0){
        return;
    }
    std::vector<Plant*> copy=source;
    std::random_shuffle(copy.begin(),copy.end());
    for(auto* p:copy){
        if(need==0){
            break;
        }
        if(std::find(offerList.begin(),offerList.end(),p)==offerList.end()){
            offerList.push_back(p);
            --need;
        }
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
    if(offer.size()<5){
        topUpRandomPlants(floor.inventory().all(),static_cast<int>(5-offer.size()),offer);
    }
    //shiffle plants so that user doesnt know ther order of the plants on offer in the order of easy,med,hard
    std::random_shuffle(offer.begin(),offer.end());
    return offer;
}

bool Manager::offerPlants(Customer& cust){
    std::vector<Plant*> offer=buildOffer(cust);
    //needs display offer -> for gui
    // int choiceIdx=getPlayerChoice();
    // Plant* chosen=offer[choice];
    // if(cust.isSatisfied(*chosen)){
        // recordSale(cust,*chosen,chosen->getSalePrice());
        // return true;
    // }else{
        // recordLostSale(cust,"Wrong PLantOffered");//need to add implimentation for the reason to be from the type of cust
        // return true;
    // }
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
