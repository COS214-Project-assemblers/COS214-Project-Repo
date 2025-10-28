#include "Director.h"

Director::Director()
{

}

Director::~Director()
{

}

Customer* Director::construct() // this is where the parameters of each buildPart will come from the json pool to get one fro the parameter
{
    builder->buildIntroDialogue();
    builder->buildPreferencesDialogue();
    builder->buildRecommendationsDialogue();
    builder->buildAcceptDialogue();
    builder->buildRejectDialogue();
    builder->buildAcceptExitDialogue();
    builder->buildRejectExitDialogue();
    
    // needs to take in the plant options that the visitor will give for the customer, so that it can be converted to a string
    builder->buildPlantOptions();

    return builder->getCustomer();
}