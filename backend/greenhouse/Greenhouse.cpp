#include "Greenhouse.h"

Greenhouse::Greenhouse()
{
    inventory = new Inventory();
}

Greenhouse::~Greenhouse()
{
    // might not delete??

    delete inventory;
}
 
void Greenhouse::addPlant(Plant* p)
{
    inventory->restock(p);
    p->setSocket(this->socket) ; 
    p->start() ; // When a plant is added to green house, start its' thread (- from Morgan)
}

Inventory* Greenhouse::getInventory()
{
    return inventory;
}

void Greenhouse::removePlant(Plant* plant){
    std::cout << "void Greenhouse::removePlant(Plant* plant)" <<std::endl; 
    this->inventory->removePlant(plant);
    
    std::cout << "\t plant->stop() ; " <<std::endl; 
    plant->join() ; // when a plant is removed from green house, stop its' thread ??? ( -from Morgan)
}

void Greenhouse::setSocket(GreenSock* greenSocket) {
    this->socket = greenSocket ; 
}