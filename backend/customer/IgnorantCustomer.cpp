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

}

void IgnorantCustomer::reactToRecommendations() 
{
    cout << "Ignorant Customer: \"Oh wow, those sound perfect for someone like me!\"\n";
}

void IgnorantCustomer::thankAndExit() 
{
    cout << "Ignorant Customer: \"Thanks! I hope I don't mess this up!\"\n";
}