#ifndef GREENFINGERCUSTOMER_H
#define GREENFINGERCUSTOMER_H

#include "Customer.h"

class GreenFingerCustomer : public Customer
{
    private:
        void introduce();
        void expressPreferences();
        void askForRecommendations();
        void reactToRecommendations();
        void thankAndExit();

    public:
        GreenFingerCustomer();
        ~GreenFingerCustomer();
        
        void accept(CustomerVisitor& cV) override;
        const Plant* considerOptions(const std::vector<const Plant*> offers)const override;
};

#endif