/**
 * @file Plant.h
 * @brief Defines the abstract base class for all Plant objects used in the system.
 */

#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

#include <thread>
#include <atomic>

#include "GreenSock.h"

class Health ;
class PlantState;
class GreenhouseStaff;

using namespace std;

/**
 * @class Plant
 * @brief Abstract base class representing a plant entity in the greenhouse simulation.
 *
 * This class serves as the foundation for all specific plant types (e.g., Succulent, Flower, Tree).
 * It provides common attributes such as category, variety, pricing, and state management,
 * and defines an interface for cloning and observer interaction.
 */
class Plant
{
    private:
        /**
         * @brief The broad category of the plant, such as "Succulent", "Flower", or "Tree".
         */
        string plantCategory;

        /**
         * @brief The specific variety within the plant category, such as "Daisy", "Cactus", or "Lemon".
         */
        string plantVariety;

        /**
         * @brief The cost to the player when purchasing the plant for cultivation in the greenhouse.
         */
        float costPrice;

        /**
         * @brief The retail price at which the plant can be sold to customers.
         * @details This is typically calculated as the cost price plus a 50% markup (subject to adjustment).
         */
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

        /**
         * @brief A static map linking specific plant varieties to their respective cost prices.
         */
        static map<string, float> plantCosts;

        /**
         * @brief List of greenhouse staff observers attached to this plant.
         */
        vector<GreenhouseStaff*> observerList;

        int decayIndex;
        std::atomic<bool> alive;
        std::thread thread;

    protected:
        /**
         *  @brief Pointer to the Health component representing the plant’s overall well-being.
         * */
        Health* health ;
        GreenSock* socket ; 

    public:
        /**
         * @brief Constructs a Plant object with the specified category and variety.
         * @details Used as a base constructor for all specific Plant subclasses.
         * @param [in] category The general category of the plant.
         * @param [in] variety The specific variety within that category.
         * @section memory_management Thread-related Memory Management
         * The Dynamic Health Attribute should only be Created in the concrete Products
         * because, the type of plant determines how much water/fertilizer/pruning is required
         */
        Plant(string category, string variety);

        /**
         * @brief Copy constructor used for the Prototype design pattern.
         * @details Enables cloning of existing Plant objects.
         * @param [in] original Reference to the Plant object being duplicated.
         */
        Plant(const Plant& original);

        /**
         * @brief Virtual destructor to ensure proper cleanup in derived classes.
         * NOTE - Additional Clean Up functionality for Thread Behaviour:
         *  - Deletes the dynamically allocated Health object.
         *  - Safely stops and joins the internal background thread to prevent dangling execution.
        */
        virtual ~Plant();

        /**
         * @brief Creates and returns a clone of the current Plant instance.
         * @details This pure virtual function must be implemented by all derived classes.
         * @return A pointer to the newly cloned Plant object.
         */
        virtual Plant* clone() = 0;

        /**
         * @brief Retrieves the category of the plant.
         * @return The category name as a string.
         */
        string getPlantCategory();

        /**
         * @brief Retrieves the variety of the plant.
         * @return The variety name as a string.
         */
        string getPlantVariety();

        /**
         * @brief Retrieves the purchase cost of the plant.
         * @return The cost price as a floating-point value.
         */
        float getCostPrice();

        /**
         * @brief Retrieves the selling price of the plant.
         * @return The sale price as a floating-point value.
         */
        float getSalePrice();

        /**
         * @brief Displays the plant’s details to the console for testing and debugging.
         * @details This method is intended for validation and developer testing purposes only.
         */
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
         * @brief Requests the plant's state to handle its current behaviour.
         * Delegates behaviour to the current PlantState by calling its handle() method.
         */
        void request();

        /**
         * @brief Starts the background thread that manages the plant’s lifecycle.
         * Launches the thread running the `run()` method, which periodically decays
         * the plant's health attributes and triggers observer notifications when care is needed.
         */
        void start()    ;  // start the thread

        /**
         * @brief Waits for the background thread to finish execution.
         * Ensures that any running thread is safely joined before object destruction,
         * preventing undefined behaviour or resource leaks.
         */
        void join()     ;   // join the thread

        /**
         * @brief Signals the plant's background thread to stop execution.
         * Sets the `alive` flag to false, allowing the `run()` loop to terminate gracefully.
         *  Typically followed by a call to `join()` to ensure the thread fully exits.
         */
        void stop()     ;   // signal the thread to stop


        /**
         * @brief Main loop executed by the plant’s background thread.
         * Periodically decreases water, fertilizer, and pruning values (simulating decay).
         * If any health parameter falls below a threshold, notifies greenhouse staff observers.
         * Continues running until the plant dies or `stop()` is called.
         */
        void run()      ;


        /**
         * @brief Retrieves the Health object associated with this plant.
         * This allows the greenhouse staff to make use of the appropriate handle
         * functions in the Health Class
         * @return Pointer to the plant’s Health component.
         */
        Health* getHealth()  ;

        /**
         * @brief Computes the plant’s overall health score.
         * The score is calculated as the sum of normalized water, fertilizer,
         * and pruning values. A lower score indicates declining health.
         * @return A floating-point value representing the plant’s current health.
         */
        float healthScore() ;

};

#endif
