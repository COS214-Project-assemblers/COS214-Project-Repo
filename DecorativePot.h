#ifndef DECORAATIVE_POT
#define DECORAATIVE_POT

#include "PlantDecorator.h"

class DecorativePot : public PlantDecorator {
    private:
        float potPrice = 119.99 ; ///< Fixed cost for the wrapper decoration
    public:
        DecorativePot(const Plant& original);
        virtual ~DecorativePot();
        float getSalePrice() override;
};


#endif
