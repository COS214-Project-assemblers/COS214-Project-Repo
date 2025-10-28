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

Customer* Director::construct(CustomerVisitor& v)
{
    if (!builder) 
    {
        throw runtime_error("Builder not set in Director");
    }

    builder->buildName("Default Customer");
    builder->buildIntroDialogue("Default Introduction");
    builder->buildPreferencesDialogue("Default Preferences");
    builder->buildRecommendationsDialogue("Default Recommendations");
    builder->buildAcceptDialogue("Default Accept");
    builder->buildRejectDialogue("Default Reject");
    builder->buildAcceptExitDialogue("Default Accept Exit");
    builder->buildRejectExitDialogue("Default Reject Exit");
    
    vector<Plant*> recommendedPlants = builder->accept(v);
    builder->buildPlantOptions(recommendedPlants);

    return builder->getCustomer();
}