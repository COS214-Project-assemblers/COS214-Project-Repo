#include "Director.h"

Director::Director()
{

}

Director::~Director()
{

}

Customer* Director::construct()
{
    builder->buildIntroDialogue();
    builder->buildPreferencesDialogue();
    builder->buildRecommendationsDialogue();
    builder->buildAcceptDialogue();
    builder->buildRejectDialogue();
    builder->buildAcceptExitDialogue();
    builder->buildRejectExitDialogue();

    return builder->getCustomer();
}