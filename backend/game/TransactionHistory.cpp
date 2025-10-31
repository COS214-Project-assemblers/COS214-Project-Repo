#include "TransactionHistory.h"
#include "Transaction.h"
#include "TransactionStrategy.h"

void TransactionHistory::setTransactionMem(const TransactionMem& tM){
    this->memento.push_back(tM);
}

TransactionMem TransactionHistory::getTransactionMem(int index)const{
    if(index<0 || index>=this->memento.size()){
        //Ally - idk if this is right???
        throw std::out_of_range("TransactionHistory index out of range");
    }
    return this->memento[index];
}

void TransactionHistory::print()const{
    //iterate though vector and print each memento from that day
    //Ally - not implimented fully but basic consept
    if(this->memento.empty()){
        std::cout<<"No Transactions Recorded today :("<<std::endl;
    }
    int count=0;
    for(const auto& m: this->memento){
        std::cout<<"Transaction "<<++count
                    <<"Type: "<<m.getType()
                    <<"Value: "<<m.getValue()
                    <<"Balance Before: "<<m.getBalanceB4()
                    <<"Balance After: "<<m.getBalenceAfter()
                    <<std::endl;
    }
}

bool TransactionHistory::processReturn(Ledger& l,Inventory& inv){
    if(this->memento.empty()){
        return false;
    }
    const TransactionMem& last=this->memento.back();
    TransactionStrategy* strat=new Return();
    Transaction ret(strat,last.getValue());
    TransactionMem snap=ret.createTransactionMem(l,last.getPlant());
    this->memento.push_back(snap);
    inv.restock(last.getPlant());
    return true;
}

void TransactionHistory::clear(){
    this->memento.clear();
}

bool TransactionHistory::hasBeenReturned(int tID)const{
    if(tID<0){
        return false;
    }
    for(int i=0;i<(int)this->memento.size();i++){
        if(this->memento[i].getType()=="Return" && this->memento[i].getTransactionID()==tID){
            return true;
        }
    }
    return false;
}

void TransactionHistory::markAsReturned(int tID){
    this->returnedIDs.push_back(tID);
}

int TransactionHistory::FindTransactionIDFor(const Plant* p)const{
    for(int i=0;i<(int)this->memento.size();i++){
        if(this->memento[i].getType()=="Sale" && this->memento[i].getPlant()==p){
            return this->memento[i].getTransactionID();
        }
    }
    return -1;
}