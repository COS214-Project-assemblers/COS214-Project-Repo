#include "Manager.h"
#include "TransactionMem.h"
#include "TransactionHistory.h"
#include "Sale.h"
#include "Customer.h"
#include "IgnorantCustomer.h"
#include "AverageCustomer.h"
#include "GreenFingerCustomer.h"
#include "VisitEasyCustomer.h"

Manager::Manager(SalesFloor& f):floor(f){}

bool Manager::offerPlants(Customer& cust){
    // use a random nuber generator to pick from 1 to 3 which will then pick the visitor in a switch statement
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1,3);
    int i=dist(rng);
    switch (int i)
    {
    case 1:
        VisitEasyCustomer v(floor.inventory());
        break;
    case 2:
        VisitMediumCustomer v(floor.inventory());
        break;
    default
        VisitHighCustomer v(floor.inventory());
        break;
    }
    cust.accept(v);
    const auto& offer=v.getOffer();//then show offer->player picks->recordSale/loss
    if(offer.empty()){
        return
    }
    //needs display offer -> for gui
    int choiceIdx=getPlayerChoice();
    if(choiceIdx<0 || choiceIdx>=(int)offer.size()){
        return false;
    }
    Plant* chosen=offer[choice];
    const bool correct=v.isCorrect(chosen);
    const bool returnable=v.isReturnable(chosen);
    if(correct && !returnable){//satisfied with offer, no return
        recordSale(cust,*chosen,chosen->getSalePrice());
        return true;
    }else{//not satisfied with offer
        recordSaleLoss(cust,*chosen);
        return false
    }
}

void Manager::recordSale(Customer& cust, Plant& p,double revenue){
    floor.inventoryMut().commitSale(&p);
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
    Transaction plantDiedT(new PlantDied(),value);
    TransactionMem snap=plantDiedT.createTransactionMem(ledger,&p);//creates snapshot
    hist.setTransactionMem(snap);//adds snapshot to history
}

const Inventory& Manager::inventory()const{
    return floor.inventory();
}

Inventory& Manager::inventoryMut(){
    return floor.inventoryMut();
}