#include "Manager.h"
#include "TransactionMem.h"
#include "TransactionHistory.h"
#include "Sale.h"
#include "SaleLoss.h"
#include "PlantDied.h"
#include "Return.h"
#include "Customer.h"
#include "IgnorantCustomer.h"
#include "AverageCustomer.h"
#include "GreenFingerCustomer.h"
#include "VisitEasyCustomer.h"
#include "VisitMediumCustomer.h"
#include "VisitHighCustomer.h"

Manager::Manager()
{
    floor = new SalesFloor();
}

const Inventory* Manager::getSaleInventory()
{
    return floor->inventory();
}
//classic non-json flow
// bool Manager::offerPlants(Customer& cust){
//     // use a random nuber generator to pick from 1 to 3 which will then pick the visitor in a switch statement
//     static std::mt19937 rng(std::random_device{}());
//     std::uniform_int_distribution<int> dist(1,3);
//     int i=dist(rng);
//     std::unique_ptr<CustomerVisitor> v;
//     switch (i)
//     {
//     case 1:
//         v=std::make_unique<VisitEasyCustomer>(floor.inventory());
//         break;
//     case 2:
//         v=std::make_unique<VisitMediumCustomer>(floor.inventory());
//         break;
//     default
//         v=std::make_unique<VisitHighCustomer>(floor.inventory());
//         break;
//     }
//     cust.accept(v);
//     const auto& offer=v.getOffer();//then show offer->player picks->recordSale/loss
//     if(offer.empty()){
//         return
//     }
//     //needs display offer -> for gui
//     int choiceIdx=getPlayerChoice();
//     if(choiceIdx<0 || choiceIdx>=(int)offer.size()){
//         return false;
//     }
//     Plant* chosen=offer[choice];
//     const bool correct=v.isCorrect(chosen);
//     const bool returnable=v.isReturnable(chosen);
//     if(correct && !returnable){//satisfied with offer, no return
//         recordSale(cust,*chosen,chosen->getSalePrice());
//         return true;
//     }else if(correct && returnable){//satisfied with offer, but return
//         floor.inventoryMut().restock(*chosen);
        
//     }else{//not satisfied with offer
//         recordSaleLoss(cust,*chosen);
//         return false
//     }
// }

void Manager::recordSale(Plant& p,double revenue){
    floor->inventoryMut().commitSale(&p);
    Transaction saleT(new Sale(),revenue);//creates new sale transaction
    TransactionMem snap=saleT.createTransactionMem(ledger,&p);//creates snapshot
    hist.setTransactionMem(snap);//adds snapshot to history
    //notifu gui
}

void Manager::recordSaleLoss(Customer& cust,Plant& p){
    Transaction lostSaleT(new SaleLoss(),0);//creates new sale transaction with 0 value    
    TransactionMem snap=lostSaleT.createTransactionMem(ledger,&p);//creates snapshot
    hist.setTransactionMem(snap);//adds snapshot to history
}

void Manager::recordPlantDied(Plant& p,double value){
    //needs to access the greenhouse inventory to remove plant
    //Needs implimentation for thisssss!!!!
    Transaction plantDiedT(new PlantDied(),value);
    TransactionMem snap=plantDiedT.createTransactionMem(ledger,&p);//creates snapshot
    hist.setTransactionMem(snap);//adds snapshot to history
}

void Manager::processReturns(Plant& p,double value){
    Transaction ret(new Return(),value);
    TransactionMem snap=ret.createTransactionMem(ledger,&p);//creates snapshot
    hist.setTransactionMem(snap);//adds snapshot to history
}

const Inventory* Manager::inventory()const{
    return floor->inventory();
}

Inventory& Manager::inventoryMut(){
    return floor->inventoryMut();
}
// void Manager::setTransaction(Transaction& t){
//     this->t=t;
// }

// Transaction& Manager::getTransaction(){
//     return this->t;
// }
// json Manager::offerAsJSON(Customer& cust, const std::string diff){
//     // use a random nuber generator to pick from 1 to 3 which will then pick the visitor in a switch statement
//     static std::mt19937 rng(std::random_device{}());
//     std::uniform_int_distribution<int> dist(1,3);
//     int i=dist(rng);
//     std::unique_ptr<CustomerVisitor> v;
//     switch (i)
//     {
//     case 1:
//         v=std::make_unique<VisitEasyCustomer>(floor->inventory());
//         break;
//     case 2:
//         v=std::make_unique<VisitMediumCustomer>(floor->inventory());
//         break;
//     default:
//         v=std::make_unique<VisitHighCustomer>(floor->inventory());
//         break;
//     }
//     cust.accept(*v);
//     const auto& offer=v.getOffer();//then show offer->player picks->recordSale/loss
//     const std::string custType=cust.getCustomerType();
//     return v.offerAsJSON(diff,custType);
// }

// json Manger::handleSelection(Customer& cust, int choice){
//     json result;
//     Plant* chosen=offer[choice];
//     const bool correct=v.isCorrect(chosen);
//     const bool returnable=v.isReturnable(chosen);
//     pj["Plant_category"]=p->getPlantCategory();
//     pj["Plant_variery"]=p->getPlantVariety();
//     pj["care_difficulty"]=p->getDifficulty();
//     out["Price"]=chosen->getSalePrice();
//     out["Correct"]=correct;
//     out["Returnable"]=returnable;
//     if(correct && !returnable){//satisfied with offer, no return
//         floor->inventoryMut().commitSale(*chosen);
//         recordSale(*chosen,chosen->getSalePrice());
//         out["TransactionStrat"]="Sale";
//         out["Balance"]=ledger.getBalance();
//     }else if(correct && returnable){//satisfied with offer, but return
//         floor.inventoryMut().restock(*chosen);
//         processReturns(*chosen,chosen->getSalePrice());
//         out["TransactionStrat"]="Return";
//         out["Balance"]=ledger.getBalance();
//     }else{//not satisfied with offer
//         recordSaleLoss(*chosen,chosen.getSalePrice());
//         out["TransactionStrat"]="SaleLoss";
//         out["Balance"]=ledger.getBalance();
//     }
//     return result;
// }