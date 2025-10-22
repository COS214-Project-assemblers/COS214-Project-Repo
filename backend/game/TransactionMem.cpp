#include "TransactionMem.h"

//maybe include the balance to store the state of the balance at that time?
TransactionMem::TransactionMem(std::string t,double v,double b4, double after){
    this->type=t;
    this->value=v;
    this->balanceB4=b4;
    this->balanceAfter=after;
}

const double TransactionMem::getValue()const{
    return this->value;
}

const double TransactionMem::getBalanceB4()const{
    return this->balanceB4;
}

const double TransactionMem::getBalenceAfter()const{
    this->balanceAfter;
}

const std::string TransactionMem::getType()const{
    return this->type;
}