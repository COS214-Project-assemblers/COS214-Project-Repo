#include "Greenhouse.h"

Greenhouse::Greenhouse(GreenSock* socket)
{
    this->socket = socket;
    inventory = new Inventory();
    PruningStaff* newPruningStaff = new PruningStaff();
    newPruningStaff->setGreenhouse(this);
    greenHouseStaff.push_back(newPruningStaff);
}

Greenhouse::~Greenhouse()
{
    // might not delete??

    delete inventory;

    for (GreenhouseStaff* staff : greenHouseStaff) {
        if (staff != nullptr) {
            delete staff;
        }
    }
}
 
void Greenhouse::addPlant(Plant* p)
{
    inventory->restock(p);
    p->setSocket(this->socket) ; 

    for (GreenhouseStaff* staff : greenHouseStaff) {
        p->attach(staff);
    }

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
    // plant->join() ; // when a plant is removed from green house, stop its' thread ??? ( -from Morgan)
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

void Greenhouse::setSalesFloor(SalesFloor* salesFloor)
{
    sFloor = salesFloor;
}

void Greenhouse::takeCareOfPlant(string id)
{
    Plant* carePlant = inventory->getPlant(id);
    if (carePlant == nullptr) {
        std::cout << "Could not find plant" << std::endl;
        return;
    }

    string notif = "pruning";
    carePlant->queueNotify(notif);
}