#include "SaleLoss.h"

double SaleLoss::execute(double v, double b){
    return b;
}

std::string SaleLoss::getType()const{
    return "SaleLoss";
}