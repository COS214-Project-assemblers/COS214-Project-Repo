#include "VisitHighCustomer.h"
#include "Inventory.h"

VisitHighCustomer::VisitHighCustomer(const Inventory& inv):CustomerVisitor(inv){}

vector<Plant*> VisitHighCustomer::visit(IgnorantCustomerBuilder& builder)
{
    std::vector<Plant*> easy=inv.findByDifficulty("easy");
    std::vector<Plant*> med=inv.findByDifficulty("medium");
    std::vector<Plant*> hard=inv.findByDifficulty("hard");
    addRandomPlants(easy,1,offer);
    addRandomPlants(med,3,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();

    return offer;
}

vector<Plant*> VisitHighCustomer::visit(AverageCustomerBuilder& builder)
{
    std::vector<Plant*> easy=inv.findByDifficulty("easy");
    std::vector<Plant*> med=inv.findByDifficulty("medium");
    std::vector<Plant*> hard=inv.findByDifficulty("hard");
    addRandomPlants(easy,1,offer);
    addRandomPlants(med,2,offer);
    addRandomPlants(hard,2,offer);
    finalizeOffer();

    return offer;
}

vector<Plant*> VisitHighCustomer::visit(GreenFingerCustomerBuilder& builder)
{
    std::vector<Plant*> easy=inv.findByDifficulty("easy");
    std::vector<Plant*> med=inv.findByDifficulty("medium");
    std::vector<Plant*> hard=inv.findByDifficulty("hard");
    addRandomPlants(easy,2,offer);;
    addRandomPlants(med,1,offer);
    addRandomPlants(hard,2,offer);
    finalizeOffer();

    return offer;
}