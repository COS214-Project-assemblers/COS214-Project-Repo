#ifndef CUSTOMERBUILDER_H
#define CUSTOMERBUILDER_H

#include "Customer.h"

class CustomerBuilder
{
    private:
        Customer* customer;

    public:
        CustomerBuilder();
        virtual ~CustomerBuilder();

        virtual void buildIntroDialogue(string i) = 0;
        virtual void buildPreferencesDialogue(string p) = 0;
        virtual void buildRecommendationsDialogue(string r) = 0;
        virtual void buildAcceptDialogue(string a) = 0;
        virtual void buildRejectDialogue(string r) = 0;
        virtual void buildAcceptExitDialogue(string a) = 0;
        virtual void buildRejectExitDialogue(string r) = 0;
        
        virtual void buildPlantOptions(vector<Plant*> p) = 0;

        Customer* getCustomer();

        // this is maybe where the visitor comes to recommend plants to the customer
        // needs to build the plants part of the jsonStructure of the Customer
        virtual void accept(CustomerVisitor& v) = 0;

        // considerOptions, like if the customer rejects/accepts the plant, will have to be frontend logic
        // const Plant* considerOptions(const vector<const Plant*> offers)const override;
       
};

#endif