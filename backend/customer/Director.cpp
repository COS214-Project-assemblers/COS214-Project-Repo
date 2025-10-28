#include "Director.h"

Director::Director()
{
    builder = nullptr;
}

Director::~Director()
{

}

void Director::setBuilder(CustomerBuilder* b)
{
    builder = b;
}

Customer* Director::construct() // this is where the parameters of each buildPart will come from the json pool to get one fro the parameter
{
    if (!builder) 
    {
        throw runtime_error("Builder not set in Director");
    }

    builder->buildIntroDialogue("Default Introduction");
    builder->buildPreferencesDialogue("Default Preferences");
    builder->buildRecommendationsDialogue("Default Recommendations");
    builder->buildAcceptDialogue("Default Accept");
    builder->buildRejectDialogue("Default Reject");
    builder->buildAcceptExitDialogue("Default Accept Exit");
    builder->buildRejectExitDialogue("Default Reject Exit");
    
    // needs to take in the plant options that the visitor will give for the customer, so that it can be converted to a string
    // builder->buildPlantOptions();

    return builder->getCustomer();
}