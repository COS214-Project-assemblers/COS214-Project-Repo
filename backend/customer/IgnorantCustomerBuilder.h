#ifndef IGNORANTCUSTOMERBUILDER_H
#define IGNORANTCUSTOMERBUILDER_H

#include "CustomerBuilder.h"
#include "IgnorantCustomer.h"

class IgnorantCustomerBuilder: public CustomerBuilder
{
    private:
        JSONGameConfiguration* config;

        /**
         * @brief Used to get a random dialogue option in the pool of options
         */
        mt19937 rng;

    public:
        IgnorantCustomerBuilder(JSONGameConfiguration* config);
        ~IgnorantCustomerBuilder();

        string getRandomElement(const vector<string>& v);

        void buildName(string n);
        void buildIntroDialogue(string i);
        void buildPreferencesDialogue(string p);
        void buildRecommendationsDialogue(string r);
        void buildAcceptDialogue(string a);
        void buildRejectDialogue(string r);
        void buildAcceptExitDialogue(string a);
        void buildRejectExitDialogue(string r);
        void buildPlantOptions(const vector<Plant*>& plants);

        vector<Plant*> accept(CustomerVisitor& visitor);
};

#endif