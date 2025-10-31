#include "VisitHighCustomer.h"
#include "Inventory.h"

VisitHighCustomer::VisitHighCustomer(const Inventory& inv):CustomerVisitor(inv){}

vector<Plant*> VisitHighCustomer::visit(IgnorantCustomerBuilder& builder)
{
    std::vector<Plant*> easy = findByDifficulty("easy");
    std::vector<Plant*> med = findByDifficulty("medium");
    std::vector<Plant*> hard = findByDifficulty("hard");

    addRandomPlants(easy,1,offer);
    markCorrectPlants(easy,1,false);
    addRandomPlants(med,1,offer);
    markCorrectPlants(med,1,true);
    addRandomPlants(hard,3,offer);
    finalizeOffer();

    return offer;
}

vector<Plant*> VisitHighCustomer::visit(AverageCustomerBuilder& builder)
{
    std::vector<Plant*> easy = findByDifficulty("easy");
    std::vector<Plant*> med = findByDifficulty("medium");
    std::vector<Plant*> hard = findByDifficulty("hard");

    addRandomPlants(easy,2,offer);
    markCorrectPlants(easy,2,true);
    addRandomPlants(med,1,offer);
    markCorrectPlants(med,1,false);
    addRandomPlants(hard,2,offer);
    finalizeOffer();

    return offer;
}

vector<Plant*> VisitHighCustomer::visit(GreenFingerCustomerBuilder& builder)
{
    std::vector<Plant*> easy = findByDifficulty("easy");
    std::vector<Plant*> med = findByDifficulty("medium");
    std::vector<Plant*> hard = findByDifficulty("hard");
    
    addRandomPlants(easy,3,offer);
    addRandomPlants(med,1,offer);
    markCorrectPlants(med,1,true);
    addRandomPlants(hard,1,offer);
    markCorrectPlants(hard,1,false);
    finalizeOffer();

    return offer;
}