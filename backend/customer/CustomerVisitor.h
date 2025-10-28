/**
 * @file CustomerVisitor.hs
 */
#ifndef CUSTOMERVISITOR_H
#define CUSTOMERVISITOR_H

#include <vector>
#include <algorithm>
#include <cstddef>

class Inventory;
class Plant;

//forward declarations of concrete customers
class IgnorantCustomer;
class AverageCustomer;
class GreenFingerCustomer;
/**
 * @class CustomerVisitor
 * @brief This is the abstract base class for defining operations for the concreteVisitors
 * 
 * THis class provides a set of pure virtual functions for visiting each concrete customer type.
 * Concrete visitor implimentations should define the plants that will be offered to the customer.
 * 
 * @see IgnorantCustomer
 * @see AverageCustomer
 * @see GreenFingerCustomer
 */
class CustomerVisitor{
    protected:
        const Inventory& inv;///<Read only inventory for building offers
        std::vector<Plant*> offer;///<Filled by concreteVisitors
    public:
        /**
         * @brief Constructor.
         */
        CustomerVisitor(const Inventory& inv);
        /**
         * @brief Virtual deconstructer.
         */
        virtual ~CustomerVisitor()=default;
    //helpers
        /**
         * @brief Adds random plants to the offersList
         * @param source Source of the vector from which plants may randomly be chosen
         * @param count Number of plants to add to the offersList vector
         * @param offersList Vector to add plantd to be offered to the user to pick from and then offer to the customer
         */
        void addRandomPlants(std::vector<Plant*>& source, int count, std::vector<Plant*>& offerList);
        /**
         * @brief Adds random plants from any dificulty level
         * @param source Source of the vector from whcih plants may randomly be chosen
         * @param need Number of plants to add to the offersList vector
         * @param offersList Vector to add needed plants to
         */
        void topUpRandomPlants(const std::vector<Plant*>& source, int need, std::vector<Plant*>& offerList);
        /**
         * @brief finalizes offer -> makes it shuffled + tops up if less that 5
         * @param target Number to aim for the offers vector
         */
        void finalizeOffer(std::size_t target=5);
        const std::vector<Plant*>& getOffer()const;
    //visitors
        /**
         * @brief Visit an IgnorantCustmer object.
         * @param cust Reference to the IgnorantCustomer being visited.
         */
        virtual void visitIgnorantCustomer(IgnorantCustomer& cust)=0;
        /**
         * @brief Visit an AverageCustomer object.
         * @param cust Reference to the AverageCustomer being visited.
         */
        virtual void visitAverageCustomer(AverageCustomer& cust)=0;
        /**
         * @brief Visit an GreenFingerCustomer object.
         * @param cust Reference to the GreenFingerCustomer being visited.
         */
        virtual void visitGreenfingerCustomer(GreenFingerCustomer& cust)=0;
};      

#endif