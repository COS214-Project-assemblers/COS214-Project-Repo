#include "VisitMediumCustomer.h"
#include "Inventory.h"

VisitMediumCustomer::VisitMediumCustomer(const Inventory& inv):CustomerVisitor(inv){}

void VisitMediumCustomer::visitIgnorantCustomer(IgnorantCustomer& cust){
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> med=inv.findByDifficulty("Medium");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,2,offer);
    addRandomPlants(med,2,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();
}

void VisitMediumCustomer::visitAverageCustomer(AverageCustomer& cust){
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> med=inv.findByDifficulty("Medium");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,1,offer);
    addRandomPlants(med,3,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();
}

void VisitMediumCustomer::visitGreenfingerCustomer(GreenFingerCustomer& cust){
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> med=inv.findByDifficulty("Medium");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,3,offer);;
    addRandomPlants(med,1,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();
}