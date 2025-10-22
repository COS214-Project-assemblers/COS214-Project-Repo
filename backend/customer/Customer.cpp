#include "Customer.h"

Customer::Customer()
{

}

Customer::~Customer()
{

}

void Customer::setOfferedPlants(const vector<const Plant*>& plants)
{
    offeredPlants = plants;
}

void Customer::interact(CustomerVisitor& visitor) 
{
    introduce();                    // Step 1: Customer intro
    expressPreferences();           // Step 2: Customer preferences
    askForRecommendations();        // Step 3: Customer asks for help
    accept(visitor);                // Step 4: Manager offers plants (VISITOR!)

    // After visitor offers plants, customer considers them
    chosenPlant = considerOptions(offeredPlants);

    if(chosenPlant != nullptr)
    {
        plantAccepted = true;
    }
    else
    {
        plantAccepted = false;
    }

    reactToRecommendations();       // Step 5: Customer reacts
    thankAndExit();                 // Step 6: Customer leaves
}