#include "AverageCustomer.h"

AverageCustomer::AverageCustomer() : Customer() 
{

}

AverageCustomer::~AverageCustomer() 
{
    
}

void AverageCustomer::showDialog()
{
    cout << "Average Customer: \"Hello! I'm looking to expand my plant collection.\"\n";
    cout << "Average Customer: \"I have some experience and can handle moderate care requirements.\"\n";
    cout << "Average Customer: \"What would be a good addition to my collection?\"\n\n";
}

vector<string> AverageCustomer::compileOptions()
{
    return
    {
        "Buy a Daisy - cheerful flowers with moderate care needs",
        "Buy an Aloe plant - medicinal and relatively easy to grow",
        "Buy a Banana Tree - tropical look but needs lots of space"
    };
}

void AverageCustomer::processChoice(int choice)
{
    switch (choice)
    {
        case 1:
            cout << "\nAverage Customer: \"Daisies are lovely! They'd look great in my garden. I'll take them!\"\n";
            break;
        case 2:
            cout << "\nAverage Customer: \"Aloe is practical and nice looking. Good suggestion!\"\n";
            break;
        case 3:
            cout << "\nAverage Customer: \"A banana tree? My yard might be too small for that...\"\n";
            break;
        default:
            cout << "\nAverage Customer: \"I'm not convinced that's what I'm looking for...\"\n";
            break;
    }
}