#include "CustomerVisitor.h"
#include "Inventory.h"

CustomerVisitor::CustomerVisitor(const Inventory& inv):inv(inv){}

void CustomerVisitor::addRandomPlants(std::vector<Plant*>& source, int count, std::vector<Plant*>& offerList){
    if(source.empty()){
        return;
    }
    std::random_shuffle(source.begin(),source.end());
    for(int i=0;i<count && i<(int)source.size();i++){
        offerList.push_back(source[i]);
    }
}

void CustomerVisitor::topUpRandomPlants(const std::vector<Plant*>& source, int need, std::vector<Plant*>& offerList){
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

void CustomerVisitor::finalizeOffer(std::size_t target){
    if(offer.size()<target){
        topUpRandomPlants(inv.all(),static_cast<int>(target-offer.size()),offer);
    }
    std::random_shuffle(offer.begin(),offer.end());
}

const std::vector<Plant*>& CustomerVisitor::getOffer()const{
    return this->offer;
}