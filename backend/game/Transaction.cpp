#include "Transaction.h"

Transaction::Transaction(TransactionStrategy* tS,double v){
    this->tS=tS;
    this->value=v;
}

TransactionMem Transaction::createTransactionMem(Ledger& ledger)const{
    double b4=ledger.getBalance();
    double after=this->tS->execute(this->value,b4);
    ledger.setBalance(after);
    return TransactionMem(this->tS->getType(),this->value,b4,after);
}


double Transaction::getValue()const{
    return this->value;
}

std::string Transaction::getType()const{
    return this->tS->getType();
}