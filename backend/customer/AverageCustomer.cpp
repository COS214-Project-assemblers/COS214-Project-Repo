#include "AverageCustomer.h"

AverageCustomer::AverageCustomer() : Customer() 
{

}

AverageCustomer::~AverageCustomer() 
{
    
}

void AverageCustomer::introduce() 
{
    cout << "Average Customer: \"Hello! I'm looking to expand my plant collection.\"\n";
}

void AverageCustomer::expressPreferences() 
{
    cout << "Average Customer: \"I have some experience and can handle moderate care requirements.\"\n";
}

void AverageCustomer::askForRecommendations() 
{
    cout << "Average Customer: \"What would be a good addition to my collection?\"\n";
}

void AverageCustomer::accept(CustomerVisitor& v)
{
    v.visitAverageCustomer(*this);
}

const Plant* AverageCustomer::considerOptions(const std::vector<const Plant*> offers)const{
// this is where the user is prompted with offers and has to choose one to offer to the customer
// if the user chose the correct option, return the plant, otherwise return nullptr
}

void AverageCustomer::reactToRecommendations() 
{
    if (plantAccepted && chosenPlant) 
    {
        cout << "Average Customer: \"Great! This will be a nice addition to my collection!\"\n";
    } 
    else 
    {
        cout << "Average Customer: \"I'm not convinced that's what I'm looking for...\"\n";
    }
}

void AverageCustomer::thankAndExit() 
{
    if (plantAccepted) 
    {
        cout << "Average Customer: \"Thanks for the help!\"\n";
    } 
    else 
    {
        cout << "Average Customer: \"I'll think about it. Thanks anyway.\"\n";
    }
}