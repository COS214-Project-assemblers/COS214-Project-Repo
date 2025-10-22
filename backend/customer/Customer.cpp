// #include "Customer.h"

// Customer::Customer()
// {

// }

// Customer::~Customer()
// {

// }

void Customer::interact(CustomerVisitor& visitor) 
{
    introduce();                    // Step 1: Customer intro
    expressPreferences();           // Step 2: Customer preferences
    askForRecommendations();        // Step 3: Customer asks for help
    receiveRecommendations(visitor); // Step 4: Manager offers plants (VISITOR!)
    reactToRecommendations();       // Step 5: Customer reacts
    thankAndExit();                 // Step 6: Customer leaves
}