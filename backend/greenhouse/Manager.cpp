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
    if(strat)
    {
        delete strat;
    }

    if(floor)
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
    //notifu gui
}

void Manager::recordRestock(Plant& p){
    if(strat)
    {
        delete strat;
    }
    strat = new Restock();
    Transaction restock(strat,p.getCostPrice());//creates new sale transaction with 0 value    
    TransactionMem snap=restock.createTransactionMem(ledger,&p);//creates snapshot
    hist.setTransactionMem(snap);//adds snapshot to history
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
}

void Manager::processReturns(Plant& p){ // This function needs to make sure that the plant that is returned, needs to actually get added back to the salesfloor
    int id=hist.FindTransactionIDFor(&p);
    if(id<0){
        return;
    }
    if(hist.hasBeenReturned(id)){
        return;
    }   
    if(strat){
        delete strat;
    }
    strat = new Return();
    Transaction ret(strat,p.getSalePrice());//creates new sale transaction with 0 value
    TransactionMem snap=ret.createTransactionMem(ledger,&p);//creates snapshot
    snap.setReturnedID(id);//records the return ID in the memento class
    hist.markAsReturned(id);//maks the transaction as returned
    hist.setTransactionMem(snap);//adds snapshot to history
    hist.markAsReturned(snap.getTransactionID());//maks the transaction as returned
    floor->inventoryMut().restock(&p);
}

const Inventory* Manager::inventory()const{
    return floor->inventory();
}

Inventory& Manager::inventoryMut(){
    return floor->inventoryMut();
}