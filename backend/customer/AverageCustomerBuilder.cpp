/**
 * @file AverageCustomerBuilder.cpp
 * @brief Implements the AverageCustomerBuilder class functionality.
 */

#include "AverageCustomerBuilder.h"

AverageCustomerBuilder::AverageCustomerBuilder(GameConfiguraton* c) : CustomerBuilder()
{
    customer = new AverageCustomer();
    config = c;

    rng.seed(chrono::system_clock::now().time_since_epoch().count());
}

AverageCustomerBuilder::~AverageCustomerBuilder()
{
    
}

string AverageCustomerBuilder::getRandomElement(const vector<string>& v) 
{
    if (v.empty()) 
    {
        return "";
    }

    uniform_int_distribution<size_t> dist(0, v.size() - 1);

    return v[dist(rng)];
}

void AverageCustomerBuilder::buildName(string n)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& averageData = customerTypes["average"];
        auto& nameOptions = averageData["name"];
        string selectedName = getRandomElement(nameOptions);
        customer->setName(selectedName);
    } 
    catch (const std::exception& e) 
    {
        customer->setName(n);
    }
}

void AverageCustomerBuilder::buildIntroDialogue(string i)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& averageData = customerTypes["average"];
        auto& introOptions = averageData["introduce"];
        string selectedDialogue = getRandomElement(introOptions);

        customer->setIntroductionDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setIntroductionDialogue(i);
    }
}

void AverageCustomerBuilder::buildPreferencesDialogue(string p)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& averageData = customerTypes["average"];
        auto& prefOptions = averageData["preferences"];
        string selectedDialogue = getRandomElement(prefOptions);

        customer->setPreferencesDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setPreferencesDialogue(p);
    }
}

void AverageCustomerBuilder::buildRecommendationsDialogue(string r)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& averageData = customerTypes["average"];
        auto& recOptions = averageData["recommendations"];
        string selectedDialogue = getRandomElement(recOptions);

        customer->setRecommendationsDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setRecommendationsDialogue(r);
    }
}

void AverageCustomerBuilder::buildAcceptDialogue(string a)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& averageData = customerTypes["average"];
        auto& acceptOptions = averageData["accept"];
        string selectedDialogue = getRandomElement(acceptOptions);

        customer->setAcceptDialogue(selectedDialogue);
    } 
    catch (const std::exception& e) 
    {
        customer->setAcceptDialogue(a);
    }
}

void AverageCustomerBuilder::buildRejectDialogue(string r)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& averageData = customerTypes["average"];
        auto& rejectOptions = averageData["reject"];
        string selectedDialogue = getRandomElement(rejectOptions);

        customer->setRejectDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setRejectDialogue(r);
    }
}

void AverageCustomerBuilder::buildAcceptExitDialogue(string a)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& averageData = customerTypes["average"];
        auto& acceptExitOptions = averageData["acceptExit"];
        string selectedDialogue = getRandomElement(acceptExitOptions);

        customer->setAcceptExitDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setAcceptExitDialogue(a);
    }
}

void AverageCustomerBuilder::buildRejectExitDialogue(string r)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& averageData = customerTypes["average"];
        auto& rejectExitOptions = averageData["rejectExit"];
        string selectedDialogue = getRandomElement(rejectExitOptions);
        
        customer->setRejectExitDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setRejectExitDialogue(r);
    }
}

void AverageCustomerBuilder::buildPlantOptions(const vector<Plant*>& plants)
{
    customer->setOfferedPlants(plants);
}

vector<Plant*> AverageCustomerBuilder::accept(CustomerVisitor& visitor)
{
    return visitor.visit(*this);
}