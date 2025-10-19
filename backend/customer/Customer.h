#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

//forward declarations so there is no circular dependancy
class CustomerVisitor;
class Plant;

class Customer
{
    private:
        virtual void showDialog() = 0;
        virtual vector<string> compileOptions() = 0;
        virtual void processChoice(int choice) = 0;

    protected:
        int getPlayerChoice(vector<string> options);
        std::string generateRejectionDialogue();

    public:
        Customer();
        virtual ~Customer();
        virtual void accept(CustomerVisitor& cV)=0;
        virtual const Plant* considerOptions(const std::vector<const Plant*> offers)const=0;
        void helpCustomer();
};

#endif