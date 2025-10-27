#include "VisitEasyCustomer.h"
#include "Inventory.h"

VisitEasyCustomer::VisitEasyCustomer(const Inventory& inv):CustomerVisitor(inv){}

void VisitEasyCustomer::visitIgnorantCustomer(IgnorantCustomer& cust){
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> med=inv.findByDifficulty("Medium");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,3,offer);
    addRandomPlants(med,1,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();
}

void VisitEasyCustomer::visitAverageCustomer(AverageCustomer& cust){
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> med=inv.findByDifficulty("Medium");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,2,offer);
    addRandomPlants(med,2,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();
}

void VisitEasyCustomer::visitGreenfingerCustomer(GreenFingerCustomer& cust){
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,4,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();
}