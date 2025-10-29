#include "Manager.h"
#include "Transaction.h"
#include "TransactionMem.h"
#include "TransactionHistory.h"
#include "ledger.h"
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
    // int choiceIdx=getPlayerChoice();
    // Plant* chosen=offer[choice];
    // if(cust.isSatisfied(*chosen)){
        // recordSale(cust,*chosen,chosen->getSalePrice());
        // return true;
    // }else{
        // recordLostSale(cust,"Wrong PLantOffered");//need to add implimentation for the reason to be from the type of cust
        // return true;
    // }
    return true;
}

bool Manager::assistNextCust(){
    if(!floor.hasCustomers()){
        return false;
    }
    Customer* c=floor.frontCust();
    offerPlants(*c);
    return true;
}

void Manager::recordSale(Customer& cust, Plant& p,double revenue){
    floor.inventoryMut().commitSale(&p);
    Transaction saleT(new Sale(),revenue);
    TransactionMem snap=saleT.createTransactionMem(ledger,&p);
    hist.setTransactionMem(snap);
    //notifu gui
    
    floor.moveToCustHist(&cust);
}

void Manager::recordLostSale(Customer& cust,std::string reason){
    //need to impliment

}
