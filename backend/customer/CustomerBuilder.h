#ifndef CUSTOMERBUILDER_H
#define CUSTOMERBUILDER_H

#include "Customer.h"
#include "CustomerVisitor.h"
#include "JSONGameConfiguration.h"

#include <random>
#include <chrono>

class CustomerBuilder
{
    protected:
        Customer* customer;

    public:
        CustomerBuilder();
        virtual ~CustomerBuilder();

        virtual void buildName(string n) = 0;
        virtual void buildIntroDialogue(string i) = 0;
        virtual void buildPreferencesDialogue(string p) = 0;
        virtual void buildRecommendationsDialogue(string r) = 0;
        virtual void buildAcceptDialogue(string a) = 0;
        virtual void buildRejectDialogue(string r) = 0;
        virtual void buildAcceptExitDialogue(string a) = 0;
        virtual void buildRejectExitDialogue(string r) = 0;
        
        virtual void buildPlantOptions(vector<Plant*> p) = 0;

        Customer* getCustomer();

        // The visitor will visit this specific builder type
        // then it will return the Plants that the visitor want to offer to the customer
        virtual vector<Plant*> accept(CustomerVisitor& visitor) = 0;
};

#endif