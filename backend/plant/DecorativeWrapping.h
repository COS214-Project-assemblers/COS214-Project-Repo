#ifndef DECORAATIVE_WRAPPER
#define DECORAATIVE_WRAPPER

#include "PlantDecorator.h"

class DecorativeWrapping : public PlantDecorator {
    private:
        float wrapperPrice = 7.99 ;  ///< Fixed cost for the wrapper decoration
    public:
        DecorativeWrapping(Plant* original);
        virtual ~DecorativeWrapping();
        float getSalePrice() override ;
};

#endif
