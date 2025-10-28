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
        Customer* construct(CustomerVisitor& v);
};

#endif