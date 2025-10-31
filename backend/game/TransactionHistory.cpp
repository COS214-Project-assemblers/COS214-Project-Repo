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

void TransactionHistory::clear(){
    this->memento.clear();
}

bool TransactionHistory::hasBeenReturned(int tID)const{
    if(tID<0){
        return false;
    }
    for(const auto& t : this->memento){
        if(t.getType()=="Return" && t.getReturnedID()==tID){
            return true;
        }
    }
    return false;
}

int TransactionHistory::FindTransactionIDFor(const Plant* p)const{
    for(int i=0;i<(int)this->memento.size();i++){
        if(this->memento[i].getType()=="Sale" && this->memento[i].getPlant()==p){
            return this->memento[i].getTransactionID();
        }
    }
    return -1;
}