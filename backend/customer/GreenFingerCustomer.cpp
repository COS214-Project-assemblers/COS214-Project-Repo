/**
 * @file GreenFingerCustomer.cpp
 * @brief Implements the functionality defined in the GreenFingerCustomer class.
 */

#include "GreenFingerCustomer.h"

GreenFingerCustomer::GreenFingerCustomer() : Customer() 
{

}

GreenFingerCustomer::~GreenFingerCustomer() 
{
    
}

void GreenFingerCustomer::introduce() 
{
    cout << "Green Finger Customer: \"Greetings! I'm an experienced plant enthusiast.\"\n";
}

void GreenFingerCustomer::expressPreferences() 
{
    cout << "Green Finger Customer: \"I'm looking for challenging plants that require expert care.\"\n";
}

void GreenFingerCustomer::askForRecommendations() 
{
    cout << "Green Finger Customer: \"What rare or difficult plants do you have?\"\n";
}

void GreenFingerCustomer::accept(CustomerVisitor& v)
{
    v.visitGreenfingerCustomer(*this);
}

const Plant* GreenFingerCustomer::considerOptions(const std::vector<const Plant*> offers)const{
// this is where the user is prompted with offers and has to choose one to offer to the customer
// if the user chose the correct option, return the plant, otherwise return nullptr
}

void GreenFingerCustomer::reactToRecommendations() 
{
    if (plantAccepted && chosenPlant) 
    {
        cout << "Green Finger Customer: \"Excellent! This will be a magnificent addition to my conservatory!\"\n";
    } 
    else 
    {
        cout << "Green Finger Customer: \"I was hoping for more challenging plants...\"\n";
    }
}

void GreenFingerCustomer::thankAndExit() 
{
    if (plantAccepted) 
    {
        cout << "Green Finger Customer: \"I'm excited to add this to my collection. Thank you!\"\n";
    } 
    else 
    {
        cout << "Green Finger Customer: \"I'll check back later for new arrivals.\"\n";
    }
}