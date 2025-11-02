#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include "Inventory.h"
#include "GreenSock.h"
#include "SalesFloor.h"
#include "PruningStaff.h"

class Greenhouse
{
    private:
        Inventory* inventory;
        GreenSock* socket;
        SalesFloor* sFloor;
        vector<GreenhouseStaff*> greenHouseStaff;
    public:
        Greenhouse(GreenSock* socket);
        ~Greenhouse();

        /**
         * @brief This function will be used to add a Plant into the inventory of the Greenhouse
         */
        void addPlant(Plant* p);

        Inventory* getInventory();
        /**
         * @brief removes a plant from the greenhouse inventory
         * @param plant Reference to the Plant being removed
         */
        Plant* removePlant(Plant* plant);
        void takeCareOfPlant(string id);
        void setSalesFloor(SalesFloor* salesFloor);
        void startThreads() ; 
        void setSocket(GreenSock* greenSocket) ;
        void movePlant(Plant* plant);

};

#endif