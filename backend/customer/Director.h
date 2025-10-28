#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "CustomerBuilder.h"
#include "CustomerVisitor.h"

class Director
{
    private:
        CustomerBuilder* builder;

    public:
        Director();
        ~Director();

        void setBuilder(CustomerBuilder* b);
        void construct(CustomerVisitor& v);

        string getCustomerJsonStructure();
};

#endif