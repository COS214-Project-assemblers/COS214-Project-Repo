#include "Return.h"

Return::Return(){

}

Return::~Return(){

}

double Return::execute(double v, double b){
    return b-v;
}

std::string Return::getType(){
    return "Return";
}