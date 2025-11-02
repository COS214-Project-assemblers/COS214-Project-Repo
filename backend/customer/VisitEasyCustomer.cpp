#include "VisitEasyCustomer.h"
#include "Inventory.h"

VisitEasyCustomer::VisitEasyCustomer(const Inventory& inv):CustomerVisitor(inv){}

vector<Plant*> VisitEasyCustomer::visit(IgnorantCustomerBuilder& builder)
{
    std::vector<Plant*> easy = findByDifficulty("easy");
    std::vector<Plant*> med = findByDifficulty("medium");
    std::vector<Plant*> hard = findByDifficulty("hard");



    addRandomPlants(easy,3,offer);
    markCorrectPlants(easy,3,false);//add param for wherther to make as returnable or not? -> this one is NOT returnable
    addRandomPlants(med,1,offer);
    // markCorrectPlants(med,1,true);//this one would be returnable
    addRandomPlants(hard,1,offer);
    finalizeOffer();

    return offer;
}

vector<Plant*> VisitEasyCustomer::visit(AverageCustomerBuilder& builder)
{
    std::vector<Plant*> easy = findByDifficulty("easy");
    std::vector<Plant*> med = findByDifficulty("medium");
    std::vector<Plant*> hard = findByDifficulty("hard");

    addRandomPlants(easy,1,offer);
    // markCorrectPlants(easy,1,true);
    addRandomPlants(med,3,offer);
    markCorrectPlants(med,3,false);
    addRandomPlants(hard,1,offer);
    finalizeOffer();

    return offer;
}

vector<Plant*> VisitEasyCustomer::visit(GreenFingerCustomerBuilder& builder)
{
    std::vector<Plant*> easy = findByDifficulty("easy");
    std::vector<Plant*> med = findByDifficulty("medium");
    std::vector<Plant*> hard = findByDifficulty("hard");
    
    addRandomPlants(easy,1,offer);
    addRandomPlants(med,1,offer);
    // markCorrectPlants(med,1,true);
    addRandomPlants(hard,3,offer);
    markCorrectPlants(hard,1,false);
    finalizeOffer();

    return offer;
}