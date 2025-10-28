#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "CustomerBuilder.h"

class Director
{
    private:
        CustomerBuilder* builder;

    public:
        Director();
        ~Director();

        void setBuilder(CustomerBuilder* b);
        Customer* construct();
};

#endif