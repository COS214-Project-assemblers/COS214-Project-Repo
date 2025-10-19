#include "PlantDied.h"

PlantDied::PlantDied(){

}

PlantDied::~PlantDied(){

}

double PlantDied::execute(double v, double b){
    return b-v;
}

std::string PlantDied::getType(){
    return "PlantDied";
}