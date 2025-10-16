#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
    private:
        int satisfaction;

        virtual void showDialog() = 0;
        virtual void compileOptions() = 0;
        virtual void scoreSelectedOptions() = 0;

    public:
        Customer();
        virtual ~Customer();

        void helpCustomer();
};

#endif