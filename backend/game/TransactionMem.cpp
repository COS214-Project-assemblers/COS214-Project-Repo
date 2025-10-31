#include "TransactionMem.h"

//maybe include the balance to store the state of the balance at that time?
TransactionMem::TransactionMem(std::string t,double v,double b4, double after,Plant* p,int tID,int rID)
    :type(t),value(v),balanceB4(b4),balanceAfter(balanceAfter),plant(p),tranID(tID), retID(rID){
}

double TransactionMem::getValue()const{
    return this->value;
}

double TransactionMem::getBalanceB4()const{
    return this->balanceB4;
}

double TransactionMem::getBalenceAfter()const{
    return this->balanceAfter;
}

std::string TransactionMem::getType()const{
    return this->type;
}

Plant* TransactionMem::getPlant()const{
    return this->plant;
}

int TransactionMem::getTransactionID()const{
    return this->tranID;
}

int TransactionMem::getReturnedID()const{
    return this->retID;
}

void TransactionMem::setReturnedID(int tID){
    this->retID=tID;
}