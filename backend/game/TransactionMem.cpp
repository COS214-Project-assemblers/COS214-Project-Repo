#include "TransactionMem.h"

//maybe include the balance to store the state of the balance at that time?
TransactionMem::TransactionMem(TransactionStrategy* tS,double v){

}

TransactionMem::~TransactionMem(){

}

double TransactionMem::getValue(){
    return this->value;
}

double TransactionMem::getBalance(){

}

std::string TransactionMem::getType(){
    return this->tS->getType();
}