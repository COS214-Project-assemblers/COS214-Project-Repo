#include "Transaction.h"
#include "Sale.h"
#include "Return.h"
#include "Restock.h"
#include "PlantDied.h"

Transaction::Transaction(TransactionStrategy* tS,double v):tS(tS), value(v){
}

TransactionMem Transaction::createTransactionMem(Ledger& ledger,Plant* plant)const{
    if(!tS){
        throw std::runtime_error("transactionStrategy is null!");
    }
    double b4=ledger.getBalance();
    double after=this->tS->execute(this->value,b4);//update bal
    ledger.setBalance(after);
    return TransactionMem(this->tS->getType(),this->value,b4,after,plant);
}

void Transaction::setTransactionMem(const TransactionMem tM){
    TransactionStrategy* rebuilt=NULL;
    if(tM.getType()=="Sale"){
        rebuilt=new Sale();
    }else if(tM.getType()=="Return"){
        rebuilt=new Return();
    }else if(tM.getType()=="Restock"){
        rebuilt=new Return();
    }else if(tM.getType()=="PlantDied"){
        rebuilt=new PlantDied();
    }
    if(this->tS){
        delete this->tS;
    }
    this->tS=rebuilt;
    this->value=tM.getValue();
}


double Transaction::getValue()const{
    return this->value;
}

std::string Transaction::getType()const{
    return this->tS->getType();
}