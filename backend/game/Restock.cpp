#include "Restock.h"

double Restock::execute(double v, double b){
    return b-v;
}

std::string Restock::getType()const{
    return "Restock";
}