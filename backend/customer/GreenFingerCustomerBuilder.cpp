#include "GreenFingerCustomerBuilder.h"

GreenFingerCustomerBuilder::GreenFingerCustomerBuilder(JSONGameConfiguration* c) : CustomerBuilder()
{
    customer = new GreenFingerCustomer();
    config = c;

    rng.seed(chrono::system_clock::now().time_since_epoch().count());
}

GreenFingerCustomerBuilder::~GreenFingerCustomerBuilder()
{
    
}

GreenFingerCustomerBuilder::~GreenFingerCustomerBuilder()
{
    
}

string GreenFingerCustomerBuilder::getRandomElement(const vector<string>& v) 
{
    if (v.empty()) 
    {
        return "";
    }

    uniform_int_distribution<size_t> dist(0, v.size() - 1);

    return v[dist(rng)];
}

void GreenFingerCustomerBuilder::buildName(string n)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& GreenFingerData = customerTypes["greenfinger"];
        auto& nameOptions = GreenFingerData["name"];
        string selectedName = getRandomElement(nameOptions);
        customer->setName(selectedName);
    } 
    catch (const std::exception& e) 
    {
        customer->setName(n);
    }
}

void GreenFingerCustomerBuilder::buildIntroDialogue(string i)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& GreenFingerData = customerTypes["greenfinger"];
        auto& introOptions = GreenFingerData["introduce"];
        string selectedDialogue = getRandomElement(introOptions);

        customer->setIntroductionDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setIntroductionDialogue(i);
    }
}

void GreenFingerCustomerBuilder::buildPreferencesDialogue(string p)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& GreenFingerData = customerTypes["greenfinger"];
        auto& prefOptions = GreenFingerData["preferences"];
        string selectedDialogue = getRandomElement(prefOptions);

        customer->setPreferencesDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setPreferencesDialogue(p);
    }
}

void GreenFingerCustomerBuilder::buildRecommendationsDialogue(string r)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& GreenFingerData = customerTypes["greenfinger"];
        auto& recOptions = GreenFingerData["recommendations"];
        string selectedDialogue = getRandomElement(recOptions);

        customer->setRecommendationsDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setRecommendationsDialogue(r);
    }
}

void GreenFingerCustomerBuilder::buildAcceptDialogue(string a)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& GreenFingerData = customerTypes["greenfinger"];
        auto& acceptOptions = GreenFingerData["accept"];
        string selectedDialogue = getRandomElement(acceptOptions);

        customer->setAcceptDialogue(selectedDialogue);
    } 
    catch (const std::exception& e) 
    {
        customer->setAcceptDialogue(a);
    }
}

void GreenFingerCustomerBuilder::buildRejectDialogue(string r)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& GreenFingerData = customerTypes["greenfinger"];
        auto& rejectOptions = GreenFingerData["reject"];
        string selectedDialogue = getRandomElement(rejectOptions);

        customer->setRejectDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setRejectDialogue(r);
    }
}

void GreenFingerCustomerBuilder::buildAcceptExitDialogue(string a)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& GreenFingerData = customerTypes["greenfinger"];
        auto& acceptExitOptions = GreenFingerData["acceptExit"];
        string selectedDialogue = getRandomElement(acceptExitOptions);

        customer->setAcceptExitDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setAcceptExitDialogue(a);
    }
}

void GreenFingerCustomerBuilder::buildRejectExitDialogue(string r)
{
    try 
    {
        auto customerTypes = config->getCustomerTypes();
        auto& GreenFingerData = customerTypes["greenfinger"];
        auto& rejectExitOptions = GreenFingerData["rejectExit"];
        string selectedDialogue = getRandomElement(rejectExitOptions);
        
        customer->setRejectExitDialogue(selectedDialogue);
    } 
    catch (const exception& e) 
    {
        customer->setRejectExitDialogue(r);
    }
}

void GreenFingerCustomerBuilder::buildPlantOptions(const vector<Plant*>& plants)
{
    customer->setOfferedPlants(plants);
}

vector<Plant*> GreenFingerCustomerBuilder::accept(CustomerVisitor& visitor)
{
    return visitor.visit(*this);
}