/**
 * @file IgnorantCustomerBuilder.cpp
 * @brief Implements the IgnorantCustomerBuilder class functionality.
 */

#include "IgnorantCustomerBuilder.h"

IgnorantCustomerBuilder::IgnorantCustomerBuilder(GameConfiguraton* c) : CustomerBuilder()
{
    customer = new IgnorantCustomer();
    config = c;

    rng.seed(chrono::system_clock::now().time_since_epoch().count());
}

IgnorantCustomerBuilder::~IgnorantCustomerBuilder()
{

}

string IgnorantCustomerBuilder::getRandomElement(const vector<string>& v) 
{
    if (v.empty()) 
    {
        return "";
    }

    uniform_int_distribution<size_t> dist(0, v.size() - 1);

    return v[dist(rng)];
}

void IgnorantCustomerBuilder::buildName(string n)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& IgnorantData = customerTypes["ignorant"];
        auto& nameOptions = IgnorantData["name"];
        string selectedName = getRandomElement(nameOptions);
        customer->setName(selectedName);
    } 
    catch (const std::exception& e) 
    {
        customer->setName(n);
    }
}

void IgnorantCustomerBuilder::buildIntroDialogue(string i)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& IgnorantData = customerTypes["ignorant"];
        auto& introOptions = IgnorantData["introduce"];
        string selectedDialogue = getRandomElement(introOptions);

        customer->setIntroductionDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setIntroductionDialogue(i);
    }
}

void IgnorantCustomerBuilder::buildPreferencesDialogue(string p)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& IgnorantData = customerTypes["ignorant"];
        auto& prefOptions = IgnorantData["preferences"];
        string selectedDialogue = getRandomElement(prefOptions);

        customer->setPreferencesDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setPreferencesDialogue(p);
    }
}

void IgnorantCustomerBuilder::buildRecommendationsDialogue(string r)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& IgnorantData = customerTypes["ignorant"];
        auto& recOptions = IgnorantData["recommendations"];
        string selectedDialogue = getRandomElement(recOptions);

        customer->setRecommendationsDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setRecommendationsDialogue(r);
    }
}

void IgnorantCustomerBuilder::buildAcceptDialogue(string a)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& IgnorantData = customerTypes["ignorant"];
        auto& acceptOptions = IgnorantData["accept"];
        string selectedDialogue = getRandomElement(acceptOptions);

        customer->setAcceptDialogue(selectedDialogue);
    } 
    catch (const std::exception& e) 
    {
        customer->setAcceptDialogue(a);
    }
}

void IgnorantCustomerBuilder::buildRejectDialogue(string r)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& IgnorantData = customerTypes["ignorant"];
        auto& rejectOptions = IgnorantData["reject"];
        string selectedDialogue = getRandomElement(rejectOptions);

        customer->setRejectDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setRejectDialogue(r);
    }
}

void IgnorantCustomerBuilder::buildAcceptExitDialogue(string a)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& IgnorantData = customerTypes["ignorant"];
        auto& acceptExitOptions = IgnorantData["acceptExit"];
        string selectedDialogue = getRandomElement(acceptExitOptions);

        customer->setAcceptExitDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setAcceptExitDialogue(a);
    }
}

void IgnorantCustomerBuilder::buildRejectExitDialogue(string r)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& IgnorantData = customerTypes["ignorant"];
        auto& rejectExitOptions = IgnorantData["rejectExit"];
        string selectedDialogue = getRandomElement(rejectExitOptions);
        
        customer->setRejectExitDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setRejectExitDialogue(r);
    }
}

void IgnorantCustomerBuilder::buildPlantOptions(const vector<Plant*>& plants)
{
    customer->setOfferedPlants(plants);
}

vector<Plant*> IgnorantCustomerBuilder::accept(CustomerVisitor& visitor)
{
    return visitor.visit(*this);
}