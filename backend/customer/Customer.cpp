#include "Customer.h"

Customer::Customer()
{

}

Customer::~Customer()
{

}

void Customer::helpCustomer()
{
    showDialog();
    
    vector<string> options = compileOptions();

    cout << "\nChoose an option:\n";
    for (size_t i = 0; i < options.size(); ++i) 
    {
        cout << (i + 1) << ". " << options[i] << "\n";
    }
    
    int choice = getPlayerChoice(options);
    
    processChoice(choice);
}

int Customer::getPlayerChoice(vector<string> options) 
{
    int choice;

    while (true) 
    {
        cout << "Enter your choice (1-" << options.size() << "): ";
        cin >> choice;
        
        if (choice < 1 || choice > static_cast<int>(options.size())) 
        {
            cout << "Invalid choice. Please try again.\n";
        } 
        else 
        {
            break;
        }
    }

    return choice;
}