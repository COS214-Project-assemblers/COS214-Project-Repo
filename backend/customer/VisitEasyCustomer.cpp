#include "VisitEasyCustomer.h"
#include "Inventory.h"

VisitEasyCustomer::VisitEasyCustomer(const Inventory& inv):CustomerVisitor(inv){}

void VisitEasyCustomer::visitIgnorantCustomer(IgnorantCustomer& cust){
    //create vectors of each difficulty
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> med=inv.findByDifficulty("Medium");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    //this is the easy level, so there are 3 correct plants for this customer type
    addRandomPlants(easy,3,offer);//correct answers for user
    addRandomPlants(med,1,offer);
    addRandomPlants(hard,1,offer);
    finalizeOffer();
}

void VisitEasyCustomer::visitAverageCustomer(AverageCustomer& cust){
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> med=inv.findByDifficulty("Medium");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,1,offer);
    addRandomPlants(med,3,offer);//correct answers for user
    addRandomPlants(hard,1,offer);
    finalizeOffer();
}

void VisitEasyCustomer::visitGreenfingerCustomer(GreenFingerCustomer& cust){
    std::vector<Plant*> easy=inv.findByDifficulty("Easy");
    std::vector<Plant*> med=inv.findByDifficulty("Medium");
    std::vector<Plant*> hard=inv.findByDifficulty("Hard");
    addRandomPlants(easy,1,offer);
    addRandomPlants(med,1,offer);    
    addRandomPlants(hard,3,offer);//correct answer for user
    finalizeOffer();
}