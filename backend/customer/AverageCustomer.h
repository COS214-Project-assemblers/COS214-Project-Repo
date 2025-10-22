#ifndef AVERAGECUSTOMER_H
#define AVERAGECUSTOMER_H

#include "Customer.h"

class AverageCustomer : public Customer
{
    private:
        void introduce();
        void expressPreferences();
        void askForRecommendations();
        void reactToRecommendations();
        void thankAndExit();

    public:
        AverageCustomer();
        ~AverageCustomer();

        void accept(CustomerVisitor& v) override;
        const Plant* considerOptions(const vector<const Plant*> offers)const override;
};

#endif