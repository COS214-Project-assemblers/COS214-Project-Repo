#ifndef COUT_LOG
#define COUT_LOG

#include "LogDecorator.h"

class CoutAndLog : public LogDecorator {
    public:
        /**
         * @brief cout << message << endl before log
         */
        virtual void newLog(std::string message) override;
    
};
#endif