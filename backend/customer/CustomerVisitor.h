/**
 * @file CustomerVisitor.hs
 */
#ifndef CUSTOMERVISITOR_H
#define CUSTOMERVISITOR_H

#include <vector>
#include <algorithm>
#include <cstddef>
#include <nlohmann/json.hpp>
using json=nlohmann::json;

class SalesFloor;
// class Plant;
#include "SalesFloor.h"
#include "Plant.h"

//forward declarations of concrete builders
class AverageCustomerBuilder;
class IgnorantCustomerBuilder;
class GreenFingerCustomerBuilder;
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
        // const SalesFloor& floor;///<Reference to salesFloor object
        const Inventory inv;///<Reference to inventory object
        std::vector<Plant*> offer;///<Filled by concreteVisitors
        std::vector<Plant*> correct;///<subset of plants that are correct for the customer
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
        /**
         * @brief retrieves the offer vector.
         * @return The vector of Plant pointers being offered to the customer.
         */
        const std::vector<Plant*>& getOffer()const;
        /**
         * @brief retrieves the correct plant for the customer.
         * @return Pointer to the correct Plant for the customer.
         */
        const std::vector<Plant*>& getCorrectPlant()const;
        /**
         * @brief Marks the correct plant for the customer.
         * @param source Vector of Plant pointers containing the correct plants for the customer.
         * @param count Number of correct plants to mark.
         * @param returnable Whether the correct plants are returnable or not.
         */
        void markCorrectPlants(const std::vector<Plant*>& source, int count,bool returnable);
        /**
         * @brief sets retrunable status of correct plants
         * @param i Index of the plant in the offer vector
         * @param returnable Whether the correct plants are returnable or not.
         */
        void setReturnable(int i,bool returnable);
        /**
         * @brief iscorrect plant
         * @param p Plant to check
         * @return true if correct plant, false if not
         */
        bool isAcceptable(Plant* p);
        /**
         * @brief isReturnable plant
         * @param p Plant to check
         * @return true if returnable, false if not
         */
        bool isReturnable(Plant* p);
    //JSON stuff
        // /**
        //  * @brief Loads offer data to json object
        //  * @return json object containing offer data
        //  */
        // json offerAsJSON(cosnt std::string diff, const std::string custType)const;
    //visitors
        /**
         * @brief Visit an IgnorantCustomerBuilder object.
         * @param builder Reference to the IgnorantCustomerBuilder being visited.
         */
        virtual vector<Plant*> visit(IgnorantCustomerBuilder& builder)=0;
        /**
         * @brief Visit an AverageCustomerBuilder object.
         * @param builder Reference to the AverageCustomerBuilder being visited.
         */
        virtual vector<Plant*> visit(AverageCustomerBuilder& builder)=0;
        /**
         * @brief Visit a GreenFingerCustomerBuilder object.
         * @param builder Reference to the GreenFingerCustomerBuilder being visited.
         */
        virtual vector<Plant*> visit(GreenFingerCustomerBuilder& builder)=0;
};      

#endif