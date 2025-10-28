/**
 * @file Customer.cpp
 * @brief Implements the functionality defined in the Customer class.
 */

#include "Customer.h"

Customer::Customer()
{

}

Customer::~Customer()
{

}

void Customer::setIntroductionDialogue(string i)
{
    introductionDialogue = i;
}

void Customer::setPreferencesDialogue(string p)
{
    preferencesDialogue = p;
}

void Customer::setRecommendationsDialogue(string r)
{
    recommendationsDialogue = r;
}

void Customer::setAcceptDialogue(string a)
{
    acceptDialogue = a;
}

void Customer::setRejectDialogue(string r)
{
    rejectDialogue = r;
}

void Customer::setAcceptExitDialogue(string a)
{
    acceptExitDialogue = a;
}

void Customer::setRejectExitDialogue(string r)
{
    rejectExitDialogue = r;
}

void Customer::setOfferedPlants(const vector<const Plant*>& plants)
{
    // turn that vector into some json string structure and set that result to the offeredPlants member variable
}

string Customer::getStructure()
{
    return jsonStructure;
}

string Customer::getType()
{
    return type;
}