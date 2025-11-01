/**
 * @file CustomerVisitor.cpp
 * @brief Implements the CustomerVisitor base class functionality.
 */

#include "CustomerVisitor.h"
#include "Inventory.h"

CustomerVisitor::CustomerVisitor(const Inventory& inv)
{
    std::vector<Plant*> originalPlants = inv.all();
    inventoryCopy = originalPlants;
}

CustomerVisitor::~CustomerVisitor()
{
    offer.clear();
    correct.clear();
    inventoryCopy.clear();
}

std::vector<Plant*> CustomerVisitor::findByDifficulty(const std::string& difficulty) const 
{
    std::vector<Plant*> out;

    for(auto* p : inventoryCopy) 
    {
        if(p->getDifficulty() == difficulty) 
        {
            out.push_back(p);
        }
    }

    return out;
}

void CustomerVisitor::addRandomPlants(std::vector<Plant*>& source, int count, std::vector<Plant*>& offerList)
{
    if(source.empty()) 
    {
        return;
    }

    std::random_shuffle(source.begin(), source.end());

    for(int i = 0; i < count && i < (int)source.size(); i++) 
    {
        offerList.push_back(source[i]);
    }
}

void CustomerVisitor::topUpRandomPlants(int need, std::vector<Plant*>& offerList) 
{
    if(need <= 0) return;
    
    std::vector<Plant*> copy = inventoryCopy;  // Copy our inventory
    std::random_shuffle(copy.begin(), copy.end());
    
    for(auto* p : copy) 
    {
        if(need == 0) break;

        if(std::find(offerList.begin(), offerList.end(), p) == offerList.end()) 
        {
            offerList.push_back(p);
            --need;
        }
    }
}

void CustomerVisitor::finalizeOffer(std::size_t target) 
{
    if(offer.size() < target) 
    {
        topUpRandomPlants(static_cast<int>(target - offer.size()), offer);
    }

    std::random_shuffle(offer.begin(), offer.end());
}

void CustomerVisitor::markCorrectPlants(const std::vector<Plant*>& source, int count, bool returnable) 
{
    for(int i = 0; i < count && i < (int)source.size(); i++) 
    {
        Plant* p = source[i];
        correct.push_back(p);
        p->setReturnable(returnable);
        p->setAcceptable(true);
    }
}

bool CustomerVisitor::isAcceptable(Plant* p){
    return p->isAcceptable();
}

bool CustomerVisitor::isReturnable(Plant* p){
    return p->isReturnable();
}