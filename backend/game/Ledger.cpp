#include "Ledger.h"

Ledger::Ledger(){
    this->balance=500;//initial bal is set to 500
}

double Ledger::getBalance(){
    return this->balance;
}

void Ledger::setBalance(double newBal){
    this->balance=newBal;
}

json Ledger::balToJSON()const{
    json j;
    j["balance"]=this->balance;
    return j;
}