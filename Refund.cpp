#include "Refund.h"

Refund::Refund(){

}

Refund::~Refund(){

}

double Refund::execute(double v, double b){
    return b-v;
}

std::string Refund::getType(){
    return "Refund";
}