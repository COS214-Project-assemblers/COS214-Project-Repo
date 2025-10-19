#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

//forward declarations so there is no circular dependancy
class CustomerVisitor;
class Plant;

class Customer{
    protected:
        std::string generateRejectionDialogue();
    public:
        //havent added @gerard 's func
        virtual ~Customer()=default;
        virtual void accept(CustomerVisitor& cV)=0;
        virtual const Plant* considerOptions(const std::vector<const Plant*> offers)const=0;
};

#endif