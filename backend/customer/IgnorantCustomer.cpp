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

void IgnorantCustomer::processChoice(int choice)
{
    switch (choice)
    {
        case 2:
            cout << "\nIgnorant Customer: \"A cactus! That sounds perfect for me! I can't kill something that needs so little care!\"\n";
            break;
        case 1:
            cout << "\nIgnorant Customer: \"Roses need so much care... I'd probably kill it in a week.\"\n";
            break;
        case 3:
            cout << "\nIgnorant Customer: \"A lemon tree? That sounds way too advanced for my small apartment.\"\n";
            break;
        default:
            cout << "\nIgnorant Customer: \"I'm not sure about that recommendation...\"\n";
            break;
    }
}

void IgnorantCustomer::accept(CustomerVisitor& cV){

}

const Plant* IgnorantCustomer::considerOptions(const std::vector<const Plant*> offers)const{

}