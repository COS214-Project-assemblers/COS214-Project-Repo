/**
 * @file CustomerVisitor.h
 * @brief Abstract visitor class for plant recommendation strategies for different customer types.
 */
#ifndef CUSTOMERVISITOR_H
#define CUSTOMERVISITOR_H

#include <vector>
#include <algorithm>
#include <cstddef>

class SalesFloor;
#include "SalesFloor.h"
#include "Plant.h"

class AverageCustomerBuilder;
class IgnorantCustomerBuilder;
class GreenFingerCustomerBuilder;

/**
 * @class CustomerVisitor
 * @brief Abstract base class for defining operations for the concrete visitors.
 * 
 * This class provides a set of pure virtual functions for visiting each concrete customer type.
 * Concrete visitor implementations should define the plants that will be offered to the customer
 * based on their preferences and the available inventory.
 * 
 * @see IgnorantCustomer
 * @see AverageCustomer
 * @see GreenFingerCustomer
 * @see VisitEasyCustomer
 * @see VisitMediumCustomer
 * @see VisitHighCustomer
 */
class CustomerVisitor
{
    protected:
        /**
         * @brief Own local copy of the Inventory in salesfloor
         */
        std::vector<Plant*> inventoryCopy;
        
        /**
         * @brief Plants to be offered to the customer
         */
        std::vector<Plant*> offer;

        /**
         * @brief Subset of plants that are correct for the customer's preferences
         */
        std::vector<Plant*> correct;

    public:

        /**
         * @brief Constructor.
         * @param inv Reference to the salesfloor inventory to copy plants from
         */
        CustomerVisitor(const Inventory& inv);

        /**
         * @brief Virtual destructor
         */
        virtual ~CustomerVisitor();

        /**
         * @brief Finds plants by difficulty level
         * @param difficulty Difficulty level to filter by ("easy", "medium", "hard")
         * @return Vector of plants matching the specified difficulty
         */
        std::vector<Plant*> findByDifficulty(const std::string& difficulty) const;
    
        /**
         * @brief Adds random plants to the offersList
         * @param source Source of the vector from which plants may randomly be chosen
         * @param count Number of plants to add to the offersList vector
         * @param offersList Vector to add plantd to be offered to the user to pick from and then offer to the customer
         */
        void addRandomPlants(std::vector<Plant*>& source, int count, std::vector<Plant*>& offerList);

        /**
         * @brief Adds random plants from any difficulty level
         * @param source Source of the vector from which plants may randomly be chosen
         * @param need Number of plants to add to the offersList vector
         * @param offersList Vector to add needed plants to
         */
        void topUpRandomPlants(int need, std::vector<Plant*>& offerList);

        /**
         * @brief finalizes offer -> makes it shuffled + tops up if less that 5
         * @param target Number to aim for the offers vector
         */
        void finalizeOffer(std::size_t target=5);

        /**
         * @brief Marks the correct plant for the customer.
         * @param source Vector of Plant pointers containing the correct plants for the customer.
         * @param count Number of correct plants to mark.
         * @param returnable Whether the correct plants are returnable or not.
         */
        void markCorrectPlants(const std::vector<Plant*>& source, int count, bool returnable);

        /**
         * @brief Checks if a plant is acceptable for the customer
         * @param p Plant to check
         * @return true if correct plant, false if not
         */
        bool isAcceptable(Plant* p);

        /**
         * @brief Checks if a plant is returnable
         * @param p Plant to check
         * @return true if returnable, false if not
         */
        bool isReturnable(Plant* p);

        /**
         * @brief Visit an IgnorantCustomerBuilder object.
         * @param builder Reference to the IgnorantCustomerBuilder being visited.
         * @return Vector of Plant pointers recommended for the ignorant customer
         */
        virtual vector<Plant*> visit(IgnorantCustomerBuilder& builder)=0;

        /**
         * @brief Visit an AverageCustomerBuilder object.
         * @param builder Reference to the AverageCustomerBuilder being visited.
         * @return Vector of Plant pointers recommended for the average customer
         */
        virtual vector<Plant*> visit(AverageCustomerBuilder& builder)=0;

        /**
         * @brief Visit a GreenFingerCustomerBuilder object.
         * @param builder Reference to the GreenFingerCustomerBuilder being visited.
         * @return Vector of Plant pointers recommended for the greenfinger customer
         */
        virtual vector<Plant*> visit(GreenFingerCustomerBuilder& builder)=0;
};      

#endif