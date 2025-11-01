#include "Transaction.h"
#include "Sale.h"
#include "Return.h"
#include "Restock.h"
#include "PlantDied.h"

Transaction::Transaction(TransactionStrategy* tS,double v):tS(tS), value(v){
    //just incrimenting the transaction id will help us to keep track of transactions and allow for referencing later on to prevent a transaction that has already been refunded from being refunded again
    static int nextID=1;
    this->transID=nextID++;
}

Transaction::~Transaction(){
    if(this->tS){
        delete this->tS;
        this->tS=nullptr;
    }
}

TransactionMem Transaction::createTransactionMem(Ledger& ledger,Plant* plant)const{
    if(!tS){
        throw std::runtime_error("transactionStrategy is null!");
    }
    double b4=ledger.getBalance();
    double after=this->tS->execute(this->value,b4);//update bal
    ledger.setBalance(after);
    return TransactionMem(this->tS->getType(),this->value,b4,after,plant,this->transID);
}

double Transaction::getValue()const{
    return this->value;
}

std::string Transaction::getType()const{
    return this->tS->getType();
}

int Transaction::getTransactionID()const{
    return this->transID;
}