#ifndef DECORAATIVE_ARRANGEMENT
#define DECORAATIVE_ARRANGEMENT

#include "PlantDecorator.h"

class DecorativeArrangement : public PlantDecorator {
    private:
        float arrangementPrice = 229.99 ; ///< Fixed cost for the wrapper decoration
    public:
        DecorativeArrangement(const Plant& original);
        virtual ~DecorativeArrangement();
        float getSalePrice() override;
    };


#endif
