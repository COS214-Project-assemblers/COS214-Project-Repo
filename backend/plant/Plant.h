/**
 * @file Plant.h
 * @brief Header file for the Plant class
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
 * @brief Abstract class for the Plant objects
 */
class Plant
{
    private:
        /**
         * @brief The category of plants available for creation, e.g., "Succulent", "Flower", "Tree"
         */
        string plantCategory;

        /**
         * @brief The specific variety of the plant category, e.g., "Daisy", "Cactus", "Lemon"
         */
        string plantVariety;

        /**
         * @brief The price that the Plant costs for the player to buy it, 
         * so that it can be planted in the Greenhouse
         */
        float costPrice;

        /**
         * @brief The price that the Customer has to pay to be able to buy the plant from the player's Greenhouse
         * @details This price is calculated with 50% revenue (can be discussed if it needs to change)
         */
        float salePrice;

        PlantState* plantState;
        string careType;

        /**
         * @brief A map used for getting the specific costPrice for the variety of the Plant object
         */
        static map<string, float> plantCosts;

        vector<GreenhouseStaff*> observerList;
    
    public:
        /**
         * @brief Abstract Plant constructor
         * @details The specific Plant object is created using the given parameters
         * @param [in] category The specific category of Plant objects
         * @param [in] variety The specific variety of the Plant category
         */
        Plant(string category, string variety);

        /**
         * @brief Copy constructor
         * @details This copy constructor is used for the Prototype design pattern to enable cloning 
         * @param [in] original Reference to the Plant object that is being copied from 
         */
        Plant(const Plant& original);

        /**
         * @brief Virtual destructor for polymorphism
         */
        virtual ~Plant();
        
        /**
         * @brief Pure virtual function that enables cloning for the Prototype design pattern, must be implemented by the subclasses
         */
        virtual Plant* clone() = 0;

        /**
         * @brief Getter for the Category member variable
         */
        string getPlantCategory();

        /**
         * @brief Getter for the Variety member variable
         */
        string getPlantVariety();

        /**
         * @brief Getter for the costPrice member variable
         */
        float getCostPrice();

        /**
         * @brief Getter for the salePrice member variable
         */
        float getSalePrice();

        /**
         * @brief Helper function for testing
         * @details This function only displays the details about the Plant object to the console, for testing / validation purposes
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