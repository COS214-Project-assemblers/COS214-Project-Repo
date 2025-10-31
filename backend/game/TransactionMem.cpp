#include "TransactionMem.h"

//maybe include the balance to store the state of the balance at that time?
TransactionMem::TransactionMem(std::string t,double v,double b4, double after,Plant* p,int tID){
    this->type=t;
    this->value=v;
    this->balanceB4=b4;
    this->balanceAfter=after;
    this->plant=p;
    this->transactionID=tID;
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
    return this->transactionID;
}