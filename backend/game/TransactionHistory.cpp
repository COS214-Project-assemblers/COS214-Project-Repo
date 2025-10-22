#include "TransactionHistory.h"

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

bool TransactionHistory::processReturn(Ledger& l){
    if(this->memento.empty()){
        return false;
    }
    const TransactionMem& last=this->memento.back();
    //can get rid of refund strategy, this is a better use of memento can keep other strategies.
    l.setBalance(last.getBalanceB4());
    this->memento.pop_back();
    return true;
}

void TransactionHistory::clear(){
    this->memento.clear();
}