/**
 * @file Customer.h
 */
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//forward declarations so there is no circular dependancy
class CustomerVisitor;
class Plant;

/**
 * @class Customer
 * @brief Abstract base class defining interface and shared behavior of Customer
 * 
 * The Customer class defines the interation methos with the sales floor that is used by all the customer types, such as displaying dialogue, and choosing to make purchases.
 * 
 * @see IgnorantCustomer
 * @see AverageCustomer
 * @see GreenFingerCustomer
 */

class Customer
{
    private:
        /**
         * @brief Displays the dialogue from the customer
         * This is a pure virtual class and mus t be implimented by the derived Customer classes.
         */
        virtual void showDialog() = 0;
        virtual vector<string> compileOptions() = 0;//Ally - i dont think we need this as this is done by the manager
        //Ally - im thinking it could have a random return value that allows it to choose the plant, with a small chance of it being rejected.
        virtual void processChoice(int choice) = 0;
    protected:
        int getPlayerChoice(vector<string> options);
        std::string generateRejectionDialogue();

    public:
        /**
         * @brief Default constructor
         */
        Customer();
         /**
         * @brief virtual deconstructor
         */
        virtual ~Customer();
        virtual void accept(CustomerVisitor& cV)=0;
        /**
         * @brief Allows for customer to evaluate and consider offered plants.
         * @param offers A vector of pointers to Plant objects of the plants on offer.
         * @return A pointer to the chosen Plant or NULL if none are chosen.
         */
        virtual const Plant* considerOptions(const std::vector<const Plant*> offers)const=0;
        //Ally - I dont think we need this as why would the customer help itself?
        void helpCustomer();
};

#endif