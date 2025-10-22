#include "IgnorantCustomer.h"

IgnorantCustomer::IgnorantCustomer() : Customer()
{

}

IgnorantCustomer::~IgnorantCustomer()
{

}


void IgnorantCustomer::introduce() 
{
    cout << "Ignorant Customer: \"Hi! I'm new to plants and pretty clueless.\"\n";
}

void IgnorantCustomer::expressPreferences() 
{
    cout << "Ignorant Customer: \"I need something that won't die if I forget to water it!\"\n";
}

void IgnorantCustomer::askForRecommendations() 
{
    cout << "Ignorant Customer: \"Can you recommend something impossible to kill?\"\n";
}

void IgnorantCustomer::accept(CustomerVisitor& v)
{
    v.visitIgnorantCustomer(*this);
}

const Plant* IgnorantCustomer::considerOptions(const std::vector<const Plant*> offers)const{
    // this is where the user is prompted with offers and has to choose one to offer to the customer
}

void IgnorantCustomer::reactToRecommendations() 
{
    if (plantAccepted && chosenPlant) 
    {
        cout << "Ignorant Customer: \"Perfect! This seems manageable!\"\n";
    } 
    else 
    {
        cout << "Ignorant Customer: \"I'm not sure about these options... "
             << "Maybe I should look elsewhere.\"\n";
    }
    // can maybe add satisfaction score (added functionality that is not so importnat rn)
    // with the current implementation, the customer just "leaves" when the wrong option is chosen
}

void IgnorantCustomer::thankAndExit() 
{
    if (plantAccepted) 
    {
        cout << "Ignorant Customer: \"Thanks! I hope I don't mess this up!\"\n";
    } 
    else 
    {
        cout << "Ignorant Customer: \"Thanks anyway, I'll try another store.\"\n";
    }
}