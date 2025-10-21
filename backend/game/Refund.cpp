#include "Refund.h"

double Refund::execute(double v, double b){
    return b-v;
}

std::string Refund::getType()const{
    return "Refund";
}