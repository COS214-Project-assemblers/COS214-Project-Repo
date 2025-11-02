#include "VisitMediumCustomer.h"
#include "Inventory.h"

VisitMediumCustomer::VisitMediumCustomer(const Inventory& inv):CustomerVisitor(inv){}

vector<Plant*> VisitMediumCustomer::visit(IgnorantCustomerBuilder& builder)
{
    std::vector<Plant*> easy = findByDifficulty("easy");
    std::vector<Plant*> med = findByDifficulty("medium");
    std::vector<Plant*> hard = findByDifficulty("hard");

    addRandomPlants(easy,2,offer);
    markCorrectPlants(easy,2,false);
    addRandomPlants(med,1,offer);
    addRandomPlants(hard,2,offer);
    finalizeOffer();

    return offer;
}

vector<Plant*> VisitMediumCustomer::visit(AverageCustomerBuilder& builder)
{
    std::vector<Plant*> easy = findByDifficulty("easy");
    std::vector<Plant*> med = findByDifficulty("medium");
    std::vector<Plant*> hard = findByDifficulty("hard");

    addRandomPlants(easy,2,offer);
    addRandomPlants(med,2,offer);
    markCorrectPlants(med,2,false);
    addRandomPlants(hard,1,offer);
    finalizeOffer();

    return offer;
}

vector<Plant*> VisitMediumCustomer::visit(GreenFingerCustomerBuilder& builder)
{
    std::vector<Plant*> easy = findByDifficulty("easy");
    std::vector<Plant*> med = findByDifficulty("medium");
    std::vector<Plant*> hard = findByDifficulty("hard");
    
    addRandomPlants(easy,2,offer);
    addRandomPlants(med,1,offer);
    addRandomPlants(hard,2,offer);
    markCorrectPlants(hard,2,false);
    finalizeOffer();

    return offer;
}