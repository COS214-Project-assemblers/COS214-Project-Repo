/**
 * @file Greenhouse.h
 * @brief Main greenhouse class managing plant inventory and staff
 */
#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include "Inventory.h"
#include "GreenSock.h"
#include "SalesFloor.h"
#include "PruningStaff.h"

/**
 * @class Greenhouse
 * @brief Central greenhouse management system coordinating plants, staff, and sales
 * 
 * The Greenhouse class serves as the main hub for plant management, maintaining
 * inventory, coordinating staff activities, and interfacing with the sales floor.
 * It follows the Facade pattern to provide a simplified interface to the complex
 * greenhouse subsystem.
 */
class Greenhouse
{
    private:
        Inventory* inventory;                ///< Plant inventory management
        GreenSock* socket;                   ///< WebSocket for real-time communication
        SalesFloor* sFloor;                  ///< Sales floor interface
        vector<GreenhouseStaff*> greenHouseStaff;  ///< Collection of greenhouse staff

    public:

        /**
         * @brief Constructor - initializes greenhouse with WebSocket connection
         * @param socket WebSocket connection for real-time updates
         */
        Greenhouse(GreenSock* socket);

        /**
         * @brief Destructor - cleans up greenhouse resources
         */
        ~Greenhouse();

        /**
         * @brief Adds a plant to the greenhouse inventory
         * @param p Pointer to Plant to add
         */
        void addPlant(Plant* p);

        /**
         * @brief Get greenhouse inventory
         * @return Pointer to Inventory object
         */
        Inventory* getInventory();

        /**
         * @brief Removes a plant from the greenhouse inventory
         * @param plant Reference to the Plant being removed
         * @return Pointer to removed Plant
         */
        Plant* removePlant(Plant* plant);

        /**
         * @brief Initiates care routine for a specific plant
         * @param id Plant identifier
         */
        void takeCareOfPlant(string id);

        /**
         * @brief Sets the sales floor interface
         * @param salesFloor Pointer to SalesFloor instance
         */
        void setSalesFloor(SalesFloor* salesFloor);

        /**
         * @brief Sets WebSocket connection
         * @param greenSocket Pointer to GreenSock instance
         */
        void setSocket(GreenSock* greenSocket) ;

        /**
         * @brief Moves plant from greenhouse to sales floor
         * @param plant Pointer to Plant to move
         */
        void movePlant(Plant* plant);
};

#endif