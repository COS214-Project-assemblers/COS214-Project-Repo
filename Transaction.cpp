#include "Transaction.h"

Transaction::Transaction(TransactionStrategy* tS,double v){
    this->tS=tS;
    this->value=v;
    //idk what to do with the balance becuase it almost needs to be elsewhere????
}

Transaction::~Transaction(){

}

TransactionMem Transaction::createTransactionMem(){

}

void Transaction::setTransactionMem(TransactionMem tM){

}

double Transaction::getValue(){
    return this->value;
}

double Transaction::getBalance(){

}

std::string Transaction::getType(){
    return this->tS->getType();
}