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

void Customer::setName(string n)
{
    name = n;
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

void Customer::setOfferedPlants(const vector<Plant*>& plants)
{
    json plantsArray = json::array();

    for (auto* plant : plants)
    {
        json plantObj = {
            {"id", plant->getId()},
            {"category", plant->getPlantCategory()},
            {"variety", plant->getPlantVariety()},
            {"difficulty", plant->getDifficulty()},
            {"acceptable", plant->isAcceptable() ? "yes" : "no"},
            {"returnable", plant->isReturnable() ? "yes" : "no"}
        };

        plantsArray.push_back(plantObj);
    }

    // Store it as a string (so the rest of your code works the same)
    offeredPlants = plantsArray.dump();
}

string Customer::escapeJsonString(const std::string& input) 
{
    std::string output;

    for (char c : input) 
    {
        switch (c) 
        {
            case '"':  output += "\\\""; break;
            case '\\': output += "\\\\"; break;
            case '\b': output += "\\b"; break;
            case '\f': output += "\\f"; break;
            case '\n': output += "\\n"; break;
            case '\r': output += "\\r"; break;
            case '\t': output += "\\t"; break;
            default:   output += c; break;
        }
    }

    return output;
}

string Customer::getStructure()
{
    json j = {
        {"name", name},
        {"type", type},
        {"introduction", introductionDialogue},
        {"preferences", preferencesDialogue},
        {"recommendations", recommendationsDialogue},
        {"accept", acceptDialogue},
        {"reject", rejectDialogue},
        {"acceptExit", acceptExitDialogue},
        {"rejectExit", rejectExitDialogue},
        {"offeredPlants", json::parse(offeredPlants)}
    };

    jsonStructure = j.dump();
    return jsonStructure;
}

string Customer::getType()
{
    return type;
}