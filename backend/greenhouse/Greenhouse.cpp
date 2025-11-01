#include "Greenhouse.h"

Greenhouse::Greenhouse(GreenSock* socket)
{
    this->socket = socket;
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

Plant* Greenhouse::removePlant(Plant* plant){
    std::cout << "void Greenhouse::removePlant(Plant* plant)" <<std::endl; 
    this->inventory->removePlant(plant);
    
    std::cout << "\t plant->stop() ; " <<std::endl; 
    plant->join() ; // when a plant is removed from green house, stop its' thread ??? ( -from Morgan)
    return plant;
}

void Greenhouse::setSocket(GreenSock* greenSocket) {
    this->socket = greenSocket ; 
}

void Greenhouse::movePlant(Plant* plant)
{
    if (sFloor == nullptr) {
        cout << "SaleFloor not set" << endl;
    }

    cout << "Removing plant from Greenhouse" << endl;
    removePlant(plant);
    cout << "Moving plant to salesfloor" << endl;
    sFloor->addPlant(plant);
    cout << "Moved plant to salesfloor" << endl;
}