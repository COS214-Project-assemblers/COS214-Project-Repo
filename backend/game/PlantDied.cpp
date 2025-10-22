#include "PlantDied.h"

double PlantDied::execute(double v, double b){
    return b-v;
}

std::string PlantDied::getType()const{
    return "PlantDied";
}