#include "IgnorantCustomer.h"

IgnorantCustomer::IgnorantCustomer() : Customer()
{

}

IgnorantCustomer::~IgnorantCustomer()
{

}


void IgnorantCustomer::showDialog()
{
    cout << "Customer: \"Hi there! I'm terrible with plants... but I want something nice for my place.\"\n";
    cout << "Customer: \"I don't get much sunlight in my apartment and I forget to water sometimes.\"\n";
    cout << "Customer: \"Which plant would you recommend for me?\"\n\n";
}

vector<string> IgnorantCustomer::compileOptions()
{
    return
    {
        "A cactus - they're super low maintenance!",
        "A peace lily - it does well in low light and forgives some neglect.",
        "A rose bush - it loves full sun and daily watering.",
        "A bonsai tree - they look fancy and need a lot of care."
    };
}

void IgnorantCustomer::processChoice(int choice)
{
    switch (choice)
    {
        case 2:
            cout << "Customer: \"Oh wow, a peace lily! That sounds perfect for me. Thank you!\"\n";
            break;
        case 1:
            cout << "Customer: \"A cactus? But I barely get sunlight... won't it die?\"\n";
            break;
        case 3:
            cout << "Customer: \"That sounds like a lot of work. I think I'll kill it...\"\n";
            break;
        case 4:
            cout << "Customer: \"Oh wow, that sounds hard. Maybe not for me.\"\n";
            break;
        default:
            cout << "Customer: \"I'm not sure I understood that...\"\n";
            break;
    }
}