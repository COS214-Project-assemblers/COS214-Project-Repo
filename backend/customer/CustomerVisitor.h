/**
 * @file CustomerVisitor.hs
 */
#ifndef CUSTOMERVISITOR_H
#define CUSTOMERVISITOR_h

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
    public:
        /**
         * @brief Default Constructor.
         */
        CustomerVisitor();
        /**
         * @brief Virtual deconstructer.
         */
        virtual ~CustomerVisitor()=default;
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