#include "Sale.h"

Sale::Sale(){

}

Sale::~Sale(){

}

double Sale::execute(double v, double b){
    return b+v;
}

std::string Sale::getType(){
    return "Sale";
}