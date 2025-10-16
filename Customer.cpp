#include "Customer.h"

Customer::Customer()
{
    satisfaction = 10;
}

Customer::~Customer()
{

}

void Customer::helpCustomer()
{
    showDialog();
    compileOptions();
    scoreSelectedOptions();
}