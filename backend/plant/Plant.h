#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <map>
#include <vector>
#include <iostream>

class PlantState;
class GreenhouseStaff;

using namespace std;

class Plant
{
    private:
        string plantCategory;
        string plantVariety;
        float costPrice;
        float salePrice;

        /**
         * @brief Pointer to the current state of the plant.
         */
        PlantState* plantState;

        /**
         * @brief The type of care currently required by the plant.
         * String that can be either of the following: "water", "fertilizer", "pruning".
         */
        string careType;

        static map<string, float> plantCosts;

        /**
         * @brief List of greenhouse staff observers attached to this plant.
         */
        vector<GreenhouseStaff*> observerList;
    
    public:
        Plant(string category, string variety);
        Plant(const Plant& original);
        virtual ~Plant();
        
        virtual Plant* clone() = 0;

        string getPlantCategory();
        string getPlantVariety();
        float getCostPrice();
        float getSalePrice();

        void display();



        /**
         * @brief Gets the current state of the plant.
         * @return Pointer to the current PlantState object
         */
        PlantState* getState();

        /**
         * @brief Attaches a greenhouse staff observer to this plant.
         * Adds a staff member to the observer list so they will be notified
         * when the plant requires care.
         * @param ob Pointer to the GreenhouseStaff observer to attach
         */
        void attach(GreenhouseStaff* ob);

        /**
         * @brief Detaches a greenhouse staff observer from this plant.
         * Removes a staff member from the observer list so they will no longer
         * be notified about this plant's care requirements.
         * @param ob Pointer to the GreenhouseStaff observer to detach
         */
        void detach(GreenhouseStaff* ob);

        /**
         * @brief Notifies all attached observers about the plant's care needs.
         * Iterates through the observer list and calls update() on each staff
         * member, informing them about the required care type.
         * @param careType The type of care the plant requires
         */
        void notify(string& careType);
        string getCareType();

        /**
         * @brief Sets a new state for the plant.
         * Transitions the plant to a new state, following the State pattern.
         * The previous state is deleted and replaced with the new state.
         * @param plantState Pointer to the new PlantState to set
         */
        void setState(PlantState* plantState);

        /**
         * @brief Requests the plant's state to handle its current behavior.
         * Delegates behavior to the current PlantState by calling its handle() method.
         */
        void request();
};

#endif