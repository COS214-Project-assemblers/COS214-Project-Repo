#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Customer
{
    private:
        virtual void showDialog() = 0;
        virtual vector<string> compileOptions() = 0;
        virtual void processChoice(int choice) = 0;

    protected:
        int getPlayerChoice(vector<string> options);

    public:
        Customer();
        virtual ~Customer();

        void helpCustomer();
};

#endif