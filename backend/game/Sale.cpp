#include "Sale.h"

double Sale::execute(double v, double b){
    return b+v;
}

std::string Sale::getType()const{
    return "Sale";
}