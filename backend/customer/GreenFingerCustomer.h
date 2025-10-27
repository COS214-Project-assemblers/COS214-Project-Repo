/**
 * @file GreenFingerCustomer.h
 * @brief Concrete customer class representing expert plant enthusiasts.
 */

#ifndef GREENFINGERCUSTOMER_H
#define GREENFINGERCUSTOMER_H

#include "Customer.h"

/**
 * @class GreenFingerCustomer
 * @brief Represents an experienced plant enthusiast who seeks challenging specimens.
 * 
 * This customer type exclusively prefers plants with "Expert" care level and
 * will reject easy or moderate plants as too simple for their advanced skills.
 */

class GreenFingerCustomer : public Customer
{
    private:
        void introduce();
        void expressPreferences();
        void askForRecommendations();
        void reactToRecommendations();
        void thankAndExit();

    public:
        /**
         * @brief Constructs a new GreenFingerCustomer object.
         */
        GreenFingerCustomer();

        GreenFingerCustomer(const CustomerData& data);

        /**
         * @brief Destroys the GreenFingerCustomer object.
         */        
        ~GreenFingerCustomer();
        
        /**
         * @brief Accepts a visitor for plant recommendations.
         * 
         * @param v Reference to the CustomerVisitor offering plants.
         */
        void accept(CustomerVisitor& cV) override;

        /**
         * @brief Evaluates plant options requiring expert-level care.
         * 
         * Only accepts plants with "Expert" care level. Rejects all other
         * plants as insufficiently challenging.
         * 
         * @param offers Vector of Plant pointers available for selection.
         * @return Pointer to chosen Plant if expert-level, nullptr if rejected.
         */
        const Plant* considerOptions(const vector<const Plant*> offers)const override;
};

#endif