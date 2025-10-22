#ifndef IGNORANTCUSTOMER_H
#define IGNORANTCUSTOMER_H

#include "Customer.h"

class IgnorantCustomer : public Customer
{
    private:
        void introduce();
        void expressPreferences();
        void askForRecommendations();
        void reactToRecommendations();
        void thankAndExit();

    public:
        IgnorantCustomer();
        ~IgnorantCustomer();
        
        void accept(CustomerVisitor& v) override;
        const Plant* considerOptions(const vector<const Plant*> offers)const override;
};

#endif