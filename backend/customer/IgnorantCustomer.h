/**
 * @file IgnorantCustomer.h
 * @brief Concrete customer class representing inexperienced plant buyers.
 */

#ifndef IGNORANTCUSTOMER_H
#define IGNORANTCUSTOMER_H

#include "Customer.h"

/**
 * @class IgnorantCustomer
 * @brief Represents a customer with minimal plant knowledge who needs easy-care plants.
 * 
 * This customer type prefers plants that are hard to kill and require minimal maintenance.
 * They will only accept plants with "Easy" care level and will reject complex plants.
 */
class IgnorantCustomer : public Customer
{
    private:
        void introduce();
        void expressPreferences();
        void askForRecommendations();
        void reactToRecommendations();
        void thankAndExit();

    public:
        /**
         * @brief Constructs a new IgnorantCustomer object.
         */
        IgnorantCustomer();

        /**
         * @brief Destroys the IgnorantCustomer object.
         */
        ~IgnorantCustomer();
        
        /**
         * @brief Accepts a visitor for plant recommendations.
         * 
         * Implements the Element side of Visitor pattern by dispatching to the
         * appropriate visitor method for ignorant customers.
         * 
         * @param v Reference to the CustomerVisitor offering plants.
         */
        void accept(CustomerVisitor& v) override;

        /**
         * @brief Presents plant options to user and validates selection.
         * 
         * The user must select an easy-care plant for this customer to accept.
         * Plants with "Moderate" or "Expert" care levels will be rejected.
         * 
         * @param offers Vector of Plant pointers available for selection.
         * @return Pointer to chosen Plant if easy-care, nullptr otherwise.
         */
        const Plant* considerOptions(const vector<const Plant*> offers)const override;
};

#endif