#include "Manager.h"
#include "TransactionMem.h"
#include "TransactionHistory.h"
#include "Sale.h"
#include "Restock.h"
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
    strat = nullptr;
}

Manager::~Manager()
{
    if(strat != nullptr)
    {
        delete strat;
    }

    if(floor != nullptr)
    {
        delete floor;
    }
}

const Inventory* Manager::getSaleInventory()
{
    return floor->inventory();
}

void Manager::recordSale(Plant& p){
    if(strat)
    {
        delete strat;
    }
    strat = new Sale();
    floor->inventoryMut().commitSale(&p);
    Transaction saleT(strat,p.getSalePrice());//creates new sale transaction
    TransactionMem snap=saleT.createTransactionMem(ledger,&p);//creates snapshot
    hist.setTransactionMem(snap);//adds snapshot to history
    strat=nullptr;
}

void Manager::recordRestock(Plant& p){
    if(strat)
    {
        delete strat;
    }
    strat = new Restock();
    floor->inventoryMut().restock(&p);
    Transaction restock(strat,p.getCostPrice());//creates new sale transaction with 0 value    
    TransactionMem snap=restock.createTransactionMem(ledger,&p);//creates snapshot
    hist.setTransactionMem(snap);//adds snapshot to history
    strat=nullptr;
}

void Manager::recordPlantDied(Plant& p){ // This function needs to make sure the plant that died in the greenhouse, actually gets removed from the inventory of greenhouse
    //needs to access the greenhouse inventory to remove plant
    //Needs implimentation for thisssss!!!!
    if(strat)
    {
        delete strat;
    }
    strat = new PlantDied();
    Transaction plantDiedT(strat,p.getCostPrice());//creates new sale transaction with 0 value
    TransactionMem snap=plantDiedT.createTransactionMem(ledger,&p);//creates snapshot
    hist.setTransactionMem(snap);//adds snapshot to history
    strat=nullptr;
}

bool Manager::processReturns(Plant& p){ // This function needs to make sure that the plant that is returned, needs to actually get added back to the salesfloor
    int id=hist.FindTransactionIDFor(&p);
    if(id<0){
        return false;
    }
    if(hist.hasBeenReturned(id)){
        return false;
    }   
    if(strat){
        delete strat;
    }
    strat = new Return();
    Transaction ret(strat,p.getSalePrice());//creates new sale transaction with 0 value
    TransactionMem snap=ret.createTransactionMem(ledger,&p);//creates snapshot
    snap.setReturnedID(id);//records the return ID in the memento class
    hist.setTransactionMem(snap);//adds snapshot to history
    floor->inventoryMut().restock(&p);
    strat=nullptr;
    return true;
}

const Inventory* Manager::inventory()const{
    return floor->inventory();
}

Inventory& Manager::inventoryMut(){
    return floor->inventoryMut();
}

float Manager::getBalance()
{
    return ledger.getBalance();
}

TransactionHistory Manager::getTransactionHist()const{
    return this->hist;
}