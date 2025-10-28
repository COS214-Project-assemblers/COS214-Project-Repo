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
    stringstream plantsJson;
    plantsJson << "[";
    
    for (size_t i = 0; i < plants.size(); ++i) 
    {
        if (i > 0) 
        {
            plantsJson << ",";
        }
        
        plantsJson << "{";
        plantsJson << "\"category\":\"" << escapeJsonString(plants[i]->getPlantCategory()) << "\",";
        plantsJson << "\"variety\":\"" << escapeJsonString(plants[i]->getPlantVariety()) << "\",";
        plantsJson << "\"careLevel\":\"" << escapeJsonString(plants[i]->getCareLevel()) << "\","; // this will have to be implemented in the Plant class
        plantsJson << "}";
    }
    
    plantsJson << "]";
    offeredPlants = plantsJson.str();
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
    stringstream jsonStream;

    jsonStream << "{";
    jsonStream << "\"name\":\"" << escapeJsonString(name) << "\",";
    jsonStream << "\"type\":\"" << escapeJsonString(type) << "\",";
    jsonStream << "\"introduction\":\"" << escapeJsonString(introductionDialogue) << "\",";
    jsonStream << "\"preferences\":\"" << escapeJsonString(preferencesDialogue) << "\",";
    jsonStream << "\"recommendations\":\"" << escapeJsonString(recommendationsDialogue) << "\",";
    jsonStream << "\"accept\":\"" << escapeJsonString(acceptDialogue) << "\",";
    jsonStream << "\"reject\":\"" << escapeJsonString(rejectDialogue) << "\",";
    jsonStream << "\"acceptExit\":\"" << escapeJsonString(acceptExitDialogue) << "\",";
    jsonStream << "\"rejectExit\":\"" << escapeJsonString(rejectExitDialogue) << "\",";
    jsonStream << "\"offeredPlants\":" << offeredPlants;
    jsonStream << "}";
    
    jsonStructure = jsonStream.str();
    
    return jsonStructure;
}

string Customer::getType()
{
    return type;
}