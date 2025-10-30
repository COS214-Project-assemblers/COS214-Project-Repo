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
    //need to add something to choose level of difficulty for player
    //for now just use easy as an EXAMPLE
    VisitEasyCustomer v(floor.inventory());
    cust.accept(v);
    const auto& offer=v.getOffer();//then show offer->player picks->recordSale/loss
    //needs display offer -> for gui
    int choiceIdx=getPlayerChoice();
    Plant* chosen=offer[choice];
    if(cust.isSatisfied(*chosen)){
        recordSale(cust,*chosen,chosen->getSalePrice());
        return true;
    }else{//not satisfied with offer
        recordSaleLoss(cust,*chosen);
        return true;
    }
    return true;
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