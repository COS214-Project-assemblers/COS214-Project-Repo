#include "VisitEasyCustomer.h"
#include "Inventory.h"

VisitEasyCustomer::VisitEasyCustomer(const Inventory& inv):CustomerVisitor(inv){}

vector<Plant*> VisitEasyCustomer::visit(IgnorantCustomerBuilder& builder)
{
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> med=inv.findByDifficulty("Medium");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,3,offer);
    addRandomPlants(med,1,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();

    return offer;
}

vector<Plant*> VisitEasyCustomer::visit(AverageCustomerBuilder& builder)
{
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> med=inv.findByDifficulty("Medium");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,2,offer);
    addRandomPlants(med,2,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();

    return offer;
}

vector<Plant*> VisitEasyCustomer::visit(GreenFingerCustomerBuilder& builder)
{
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,4,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();

    return offer;
}