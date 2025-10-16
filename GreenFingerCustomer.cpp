#include "GreenFingerCustomer.h"

GreenFingerCustomer::GreenFingerCustomer() : Customer() 
{

}

GreenFingerCustomer::~GreenFingerCustomer() 
{
    
}

void GreenFingerCustomer::showDialog()
{
    cout << "Customer: \"Good afternoon. I'm an experienced gardener looking for something special.\"\n";
    cout << "Customer: \"I have extensive knowledge and can handle any level of care complexity.\"\n";
    cout << "Customer: \"What rare or challenging plant would you recommend?\"\n\n";
}

vector<string> GreenFingerCustomer::compileOptions()
{
    return
    {
        "Buy a Sunflower - beautiful but quite common",
        "Buy a Jade plant - elegant succulent but relatively easy",
        "Buy an Apple Tree - requires skill to fruit well and takes years to mature"
    };
}

void GreenFingerCustomer::processChoice(int choice)
{
    switch (choice)
    {
        case 3:
            cout << "Customer: \"An apple tree! Now that's a proper challenge. I'd love to cultivate one!\"\n";
            break;
        case 2:
            cout << "Customer: \"Jade plants are nice, but I already have several varieties.\"\n";
            break;
        case 1:
            cout << "Customer: \"Sunflowers are too basic for my collection.\"\n";
            break;
        default:
            cout << "Customer: \"That doesn't match what I'm looking for.\"\n";
            break;
    }
}