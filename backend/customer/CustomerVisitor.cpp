/**
 * @file CustomerVisitor.cpp
 * @brief Implements the CustomerVisitor base class functionality.
 */

#include "CustomerVisitor.h"
#include "Inventory.h"

CustomerVisitor::CustomerVisitor(const Inventory& inv):inv(inv), correct(NULL){}

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

const std::vector<Plant*>& CustomerVisitor::getCorrectPlant()const{
    return this->correct;
}

void CustomerVisitor::setReturnable(int i,bool returnable){
    offer[i]->setReturnable(returnable);
}

// add setAcceptable with the same logic just with offer[i]->setAcceptable(acceptable);
// then in Plant add this->acceptable = acceptable;

void CustomerVisitor::markCorrectPlants(const std::vector<Plant*>& source, int count,bool returnable){
    for(int i=0;i<count && i<(int)source.size();i++){
        Plant* p=source[i];
        correct.push_back(p);
        p->setReturnable(returnable);
    }
}

bool CustomerVisitor::isCorrect(Plant* p){
    return std::find(correct.begin(),correct.end(),p)!=correct.end();
}

bool CustomerVisitor::isReturnable(Plant* p){
    return p->isReturnable();
}

// json CustomerVisitor::offerAsJSON(const std::string diff, const std::string custType)const{
//     json j;
//     j["customer_type"]=custType;//type of customer being offered to
//     j["difficulty"]=diff;//difficulty level of the game when offer was made
//     j["offer"]=json::array();
//     for(const auto* p:offer){
//         json pj;
//         pj["Plant_category"]=p->getPlantCategory();
//         pj["Plant_variery"]=p->getPlantVariety();
//         pj["care_difficulty"]=p->getDifficulty();//care difficulty of plant
//         pj["sale_price"]=p->getSalePrice();
//         pj["isReturnable"]=isReturnable(p);//checks if plants are returnable
//         pj["isCorrect"]=isCorrect(p);//if plant is a good match for customer
//         j["offer"].push_back(pj);
//     }
//     return j;
// }
//if accept no -> sale lost
//if accept yes and no return -> sale committed
//if accept yes and return -> return 

//need endpoint for yes and return