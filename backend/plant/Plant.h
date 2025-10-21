/**
 * @file Plant.h
 * @brief Defines the abstract base class for all Plant objects used in the system.
 */

#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <map>
#include <vector>
#include <iostream>

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

        PlantState* plantState;
        string careType;

        /**
         * @brief A static map linking specific plant varieties to their respective cost prices.
         */
        static map<string, float> plantCosts;

        vector<GreenhouseStaff*> observerList;
    
    public:
        /**
         * @brief Constructs a Plant object with the specified category and variety.
         * @details Used as a base constructor for all specific Plant subclasses.
         * @param [in] category The general category of the plant.
         * @param [in] variety The specific variety within that category.
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

        PlantState* getState();
        void attach(GreenhouseStaff* ob);
        void detach(GreenhouseStaff* ob);
        void notify(string& careType);
        string getCareType();
        void setState(PlantState* plantState);
        void request();
};

#endif