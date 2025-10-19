#include "IgnorantCustomer.h"

IgnorantCustomer::IgnorantCustomer() : Customer()
{

}

IgnorantCustomer::~IgnorantCustomer()
{

}


void IgnorantCustomer::showDialog()
{
    cout << "Ignorant Customer: \"Hi there! I want to buy my first plant but I'm terrible with them...\"\n";
    cout << "Ignorant Customer: \"My apartment doesn't get much sunlight and I sometimes forget to water.\"\n";
    cout << "Ignorant Customer: \"What plant should I buy that I won't kill?\"\n\n";
}

vector<string> IgnorantCustomer::compileOptions()
{
    return
    {
        "Buy a Rose - beautiful flowers that need lots of care",
        "Buy a Cactus - very low maintenance and hard to kill", 
        "Buy a Lemon Tree - grows fruit but needs lots of space and care"
    };
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