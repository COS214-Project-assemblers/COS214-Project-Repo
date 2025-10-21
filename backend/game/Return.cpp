#include "Return.h"

double Return::execute(double v, double b){
    return b-v;
}

std::string Return::getType()const{
    return "Return";
}